#include <iostream>
#include <cstring>
#include <algorithm>


using namespace std;

const int M = 1e5+1,N=1e6+1;
char a[M],b[N];
int ne[M];
int m,n;

int main()
{
    //输入
    cin>>m>>a+1>>n>>b+1;
    //计算next数组
    for(int i=2,j=0;i<=m;i++)
    {
        while(j&&a[i]!=a[j+1]) j=ne[j];
        if(a[i]==a[j+1]) j++;
        ne[i]=j;
    }
    
    //开始匹配
    for(int i=1,j=0;i<=n;i++)
    {
        while(j&&b[i]!=a[j+1]) j=ne[j];
        if (b[i]==a[j+1]) j++;
        if(j==m)
        {
            printf("%d ",i-m);
            j=ne[j];
        }
    }
}