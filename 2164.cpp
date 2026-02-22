#include <queue>
#include <iostream>
#include <string>
using namespace std;
queue<int> q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        q.push(i);
    }
    bool flag=true;
    while(q.size()>1)
    {
        if (flag)
        {
            q.pop();
            flag=false;
            continue;
        }
        else
        {
            q.push(q.front());
            q.pop();
            flag=true;
            continue;
        }
    }
    cout<<q.front()<<"\n";
}