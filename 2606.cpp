#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
void dfs(int v, vector<vector<int>> graph, vector<bool> &visited)
{
    for(int i=0; i<graph[v].size(); i++)
    {
        if(!visited[graph[v][i]])
        {
            visited[graph[v][i]]=true;
            dfs(graph[v][i],graph,visited);

        }
    }
}
void bfs(int v, vector<vector<int>> graph, vector<bool> &visited, queue<int> &q)
{
    for(int i=0; i<graph[v].size(); i++)
    {
        if(!visited[graph[v][i]])
        {
            visited[graph[v][i]]=true;
            q.push(graph[v][i]);
        }

    }
    while(!q.empty())
    {
        int next=q.front();
        q.pop();
        bfs(next,graph, visited, q);
    }
}
int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    int m;
    cin>>n;
    cin>>m;
    vector<vector<int>> graph(n+1);
    vector<bool> visited(n+1,false);
    queue<int> q;
    for(int i=0; i<m; i++)
    {
        int a1,a2;
        cin>>a1>>a2;
        
        graph[a1].push_back(a2);
        graph[a2].push_back(a1);

    }
    for(int i=1; i<=n; i++)
    {
        sort(graph[i].begin(),graph[i].end());
    }
    visited[1]=true;
    //dfs(1,graph, visited);
    bfs(1,graph,visited, q);
    int cnt=0;
    for(int i=2; i<visited.size(); i++)
    {
        if(visited[i])
        {
            cnt+=1;
        }
    }
    cout<<cnt<<"\n";
}