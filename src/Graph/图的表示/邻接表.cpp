//假设有一个有向图，包含4个顶点 {A, B, C, D} 和以下边：(A, B), (A, C), (B, C), (C, D)

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

typedef struct ListNode{
    char data;
    ListNode* next;
    ListNode(char data){
        this->data = data;
        this->next = NULL;
    }
}Node;

class Adjacency_list{
    private:
        int n; //顶点数
        std::vector<std::list<ListNode>> adj; //邻接表
    public:
        //构造函数，初始化顶点数和邻接表
        Adjacency_list(int n){
            this->n = n;
            adj.resize(n);
            for(int i = 0; i < n; i++){
                adj[i].push_back(ListNode('A' + i));
            }
        }
        //添加边
        void addEdge(int v, int w){
            adj[v].push_back(ListNode('A' + w));
        }
        //打印邻接表
        // 打印函数
        void print(){
            // 遍历每个节点
            for(int i = 0; i < n; i++){
                // 获取当前节点的邻接表
                auto node = adj[i].begin();
                // 遍历当前节点的邻接表
                for(auto it = ++adj[i].begin(); it != adj[i].end(); it++){
                    // 输出当前节点和邻接节点的数据
                    std::cout << node->data << "->" << it->data << " ";
                    std::cout << std::endl;
                }
                std::cout << std::endl;
            }
        }
};

int main()
{
    Adjacency_list graph(4);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);
    graph.print();
    return 0;
}