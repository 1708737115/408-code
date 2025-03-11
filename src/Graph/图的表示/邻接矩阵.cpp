//假设有一个有向图，包含4个顶点 {A, B, C, D} 和以下边：(A, B), (A, C), (B, C), (C, D)


#include <iostream>
#include <vector>

using namespace std;

class AdjacencyMatrix
{
    private:
        int n; //顶点数
        vector<vector<int>> adj; //邻接矩阵
        vector<char> vertices; //顶点数组
    public:
        AdjacencyMatrix(int n): n(n)
        {
            adj.resize(n, vector<int>(n, 0));
            for(int i = 0; i < n; i++)
            {
                vertices.push_back('A' + i);
            }
        }
        void addEdge(int u,int v)
        {
            adj[u][v] = 1;
            adj[v][u] = 1;
        }
        void print()
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if (adj[i][j] == 1)
                    {
                        cout<<vertices[i]<<"->"<<vertices[j]<<endl;
                    }
                }
                cout << endl;
            }
        }
};

int main()
{
    AdjacencyMatrix adjMatrix(4);
    adjMatrix.addEdge(0, 1);
    adjMatrix.addEdge(0, 2);
    adjMatrix.addEdge(1, 2);
    adjMatrix.addEdge(2, 3);
    adjMatrix.print();
}