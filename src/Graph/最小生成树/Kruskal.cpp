// Kruskal算法这里我们基于并查集来实现，这里也会实现一下并查集

#include <iostream>
#include <algorithm>

using namespace std;

const int N=100010;
int cnt=0; //记录边的数量
int p[N]; //储存并查集
int n,m; //n个点，m条边
struct E{
    int a; //边的起点
    int b; //边的终点
    int w; //边的权重
    bool operator<(const E& t) const
    {
        return w<t.w;
    }
}edge[N*2]; //储存边

int find(int x)
{
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}

int Kruskal()
{
    int res=0;//记录最小生成树的总权值
    for(int i=0;i<m;i++)
    {
        if(find(edge[i].a)!=find(edge[i].b))//判断两点是否在一个联通组中,不在则合并
        {
            p[find(edge[i].a)]=find(edge[i].b);
            cnt++;
            res+=edge[i].w;
        }
    }
    if(cnt!=n-1) return -1;
    return res;
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b,w;
        cin>>a>>b>>w;
        edge[i]={a,b,w};
    }
    sort(edge,edge+m); //按权重排序
    for(int i=1;i<=n;i++) p[i]=i; //初始化并查集
    cout<<Kruskal()<<endl;
}

//备注：
/*
    时间复杂度为O(mlogm+n),其中m为边的数量，n为点的数量,但是n的上涨速度缓慢，视为常数,
    所以时间复杂度可以视为O(mlogm),算法适用于稀疏图，即边的数量远小于点的数量。
*/