#include <iostream>
#include <vector>

using namespace std;
typedef struct ArcNode
{
    char tailvex, headvex;  // huadvex: 弧尾，tailvex: 弧头
    ArcNode *hlink, *tlink; // hlink: 弧头链，tlink: 弧尾链
} Arc;                      // 边结点结构体

typedef struct VNode
{
    char data;
    Arc *firstin, *firstout; // firstin: 入边链表头指针，firstout: 出边链表头指针
} V;                         // 顶点结构体

class Graph
{
private:
    int n;           // 顶点数
    vector<V> vexs;  // 顶点数组
    int numVertices; // 边数
public:
    Graph(int n);                            // 图结构的初始化
    void addArc(char tailvex, char headvex); // 添加边
    void printGraph();                       // 打印图结构
};

Graph::Graph(int n)
{
    this->n = n;
    numVertices = 0;
    vexs.resize(n);
    for (int i = 0; i < n; ++i)
    {
        vexs[i].data = 'A' + i;
        vexs[i].firstin = nullptr;
        vexs[i].firstout = nullptr;
    }
}

void Graph::addArc(char tailvex, char headvex)
{
    Arc *arc = new Arc;
    arc->tailvex = tailvex;
    arc->headvex = headvex;
    // 处理弧尾
    if (vexs[tailvex - 'A'].firstout == NULL)
    {
        vexs[tailvex - 'A'].firstout = arc;
    }
    else
    {
        auto l = vexs[tailvex - 'A'].firstout;
        while (l->tlink != NULL)
        {
            l = l->tlink;
        }
        l->tlink = arc;
    }
    // 处理弧头
    if (vexs[headvex - 'A'].firstin == NULL)
    {
        vexs[headvex - 'A'].firstin = arc;
    }
    else
    {
        auto l = vexs[headvex - 'A'].firstin;
        while (l->hlink != NULL)
        {
            l = l->hlink;
        }
        l->hlink = arc;
    }
    arc->tlink = NULL;
    arc->hlink = NULL;
    numVertices++;
}

void Graph::printGraph()
{
    for (int i = 0; i < numVertices; ++i)
    {
        cout << "Vertex " << i << " outgoing edges: ";
        ArcNode *arc = vexs[i].firstout;
        while (arc)
        {
            cout << "(" << arc->tailvex << ", " << arc->headvex << ") ";
            arc = arc->tlink;
        }
        cout << endl;
    }
}

//测试
int main()
{
    Graph g(4); // 创建一个包含4个顶点的图
    g.addArc('A', 'B');
    g.addArc('A', 'C');
    g.addArc('B', 'C');
    g.addArc('C', 'D');
    g.printGraph();
    return 0;
}
