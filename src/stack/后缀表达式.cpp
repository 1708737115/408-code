#include <iostream>
#include <stack>
#include <unordered_map>
#include <string>

using namespace std;

stack<int> s;//操作数栈
stack<char> op;//操作符栈
unordered_map<char,int> op_map={
    {'+',1},
    {'-',1},
    {'*',2},
    {'/',2},
};

void equal()
{
    int a=s.top();
    s.pop();
    int b=s.top();
    s.pop();
    char c=op.top();
    op.pop();
    if(c=='+') s.push(a+b);
    else if(c=='-') s.push(b-a);
    else if(c=='*') s.push(a*b);
    else if(c=='/') s.push(b/a);
}

int main()
{
    string str;
    cin>>str;
    for(int i=0;i<str.size();i++)
    {
        auto c=str[i];
        if(isdigit(c))
        {
            int num=0;
            int j=i;
            while(j<str.size()&&isdigit(str[j]))
            {
                num=num*10+str[j]-'0';
                j++;
            }
            s.push(num);
            i=j-1;
        }
        else if(c=='(') op.push(c);
        else if(c==')')
        {
            while(op.top()!='(') equal();
            op.pop();
        }
        else
        {
            while(!op.empty()&&op_map[op.top()]>=op_map[c]) equal();
            op.push(c);
        }
    }
    while(!op.empty()) equal();
    cout<<s.top()<<endl;
}