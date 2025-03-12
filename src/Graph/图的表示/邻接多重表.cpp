#include <iostream>
#include <vector>

using namespace std;

typedef struct ArcNode
{
    char ivex, jvex;
    ArcNode *ilink, *jlink;
} Arc;

typedef struct VNode
{
    char data;
    Arc *first; // 指向第一条依附该顶点的边
} V;

class Graph
{
private:
    vector<V> v;
    int n, numVertices;

public:
    Graph(int n);
    void addArc(char i, char j);
    void print();
};

Graph::Graph(int n)
{
    this->n = n;
    this->numVertices = 0;
    v.resize(n);
    for (int i = 0; i < n; i++)
    {
        v[i].first = NULL;
        v[i].data = i + 'A';
    }
}

void Graph::addArc(char i, char j)
{
    /**
     * @brief 这里我尝试了只创建一个边，但是发现会导致循环引用,选择创建两边，一个边的代码如下，可自行测试
     * void Graph::addArc(char i, char j)
{
    Arc *p = new Arc; // 创建一条边
    p->ivex = i;
    p->jvex = j;
    p->ilink = NULL;
    p->jlink = NULL;
    if (v[i - 'A'].first == NULL)
    {
        v[i - 'A'].first = p; // 将该边插入到顶点i的边表头
    }
    else
    {
        auto node = v[i - 'A'].first;
        while (node->ilink != NULL)
        {
            node = node->ilink;
        }
        node->ilink = p;
    }

    if (v[j - 'A'].first == NULL)
    {
        v[j - 'A'].first = p; // 将该边插入到顶点j的边表头
    }
    else
    {
        auto node = v[j - 'A'].first;
        while (node->jlink != NULL)
        {
            node = node->jlink;
        }
        node->jlink = p;
    }
    numVertices++;
}
     */

    // 创建新边并插入到顶点i的边列表中
    Arc *p_i = new Arc;
    p_i->ivex = i;
    p_i->jvex = j;
    p_i->ilink = nullptr;
    p_i->jlink = nullptr;

    if (v[i - 'A'].first == nullptr)
    {
        v[i - 'A'].first = p_i;
    }
    else
    {
        auto node = v[i - 'A'].first;
        while (node->ilink != nullptr)
        {
            node = node->ilink;
        }
        node->ilink = p_i;
    }

    // 创建新边并插入到顶点j的边列表中
    Arc *p_j = new Arc;
    p_j->ivex = j;
    p_j->jvex = i;
    p_j->ilink = nullptr;
    p_j->jlink = nullptr;

    if (v[j - 'A'].first == nullptr)
    {
        v[j - 'A'].first = p_j;
    }
    else
    {
        auto node = v[j - 'A'].first;
        while (node->ilink != nullptr)
        {
            node = node->ilink;
        }
        node->ilink = p_j;
    }

    // 更新边计数器
    numVertices++;
}

void Graph::print()
{
    for (int i = 0; i < n; ++i)
    {
        cout << "Vertex " << v[i].data << " outgoing edges: ";
        Arc *arc = v[i].first;
        while (arc)
        {
            cout << "(" << arc->ivex << ", " << arc->jvex << ") ";
            arc = arc->ilink; // 使用 ilink 遍历出边
        }
        cout << endl;
    }
}

int main()
{
    Graph g(4); // 创建一个包含4个顶点的图
    g.addArc('A', 'B');
    g.addArc('A', 'C');
    g.addArc('B', 'C');
    g.addArc('C', 'D');
    g.print();
    return 0;
}