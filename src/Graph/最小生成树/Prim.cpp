// 例题链接: https://www.acwing.com/problem/content/860/
/*
    测试样例
    
4 5
1 2 1
1 3 2
1 4 3
2 3 2
3 4 4

6
*/

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

const int N = 501;
int G[N][N]; // 基于邻接矩阵储存图
int dist[N]; // 最小生成树中每个顶点到最小生成树的距离
bool vis[N]; // 记录顶点是否被访问过
int n, m;    // 顶点数和边数

void Prim()
{
    memset(vis, false, sizeof(vis));
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0; // 初始化(表示从1这点开始)
    int res=0; //记录结果
    for (int i = 1; i <= n; i++)
    {
        int t = -1; // 初始化
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && (t == -1 || dist[j] < dist[t])) // 寻找最小的dist[j]且未被访问的顶点
            {
                t = j;
            }
        }
        if (dist[t] == 0x3f3f3f3f) // 如果dist[t] == 0x3f3f3f3f, 说明存在孤立点,最小生成树建不出来
        {
            cout << "No MST" << endl;
            return;
        }
        vis[t] = true; // 标记顶点t已被访问
        res += dist[t];
        for(int j = 1; j <= n; j++) // 更新dist[j]
        {
            dist[j] = min(dist[j], G[t][j]);
        }
    }
    cout<<res<<endl;
}

int main()
{
    memset(G,0x3f,sizeof(G));
    cin>>n>>m;
    while (m -- )
    {
        int a,b,c;
        cin>>a>>b>>c;
        G[a][b]=G[b][a]=min(G[a][b],c);
    }
    Prim();
}

//备注：
/*
    时间复杂度为O(n^2),和边数无关,所以适用于稠密图
*/