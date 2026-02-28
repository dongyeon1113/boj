#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/**
 * BFS (너비 우선 탐색)
 * - 시작점(v)과 연결된 모든 정점을 방문 처리함.
 * - 이 함수가 한 번 끝날 때마다 하나의 '연결 요소(덩어리)'를 다 훑은 셈임.
 */
void bfs(int start, vector<vector<int>> &graph, vector<bool> &visited)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty())
    {
        int curr = q.front();
        q.pop();

        for(int i = 0; i < (int)graph[curr].size(); i++)
        {
            int next = graph[curr][i];
            if(!visited[next]) // 아직 방문하지 않은 인접 노드가 있다면
            {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main()
{
    // Fast I/O: 데이터 양이 많을 때 필수
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m; // n: 정점의 개수, m: 간선의 개수
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    vector<bool> visited(n + 1, false);

    // 무방향 그래프(양방향) 인접 리스트 생성
    for(int i = 0; i < m; i++)
    {
        int a1, a2;
        cin >> a1 >> a2;
        graph[a1].push_back(a2);
        graph[a2].push_back(a1);
    }

    // 정점 번호가 낮은 순으로 탐색하기 위한 정렬 (필수 조건은 아니지만 습관화!)
    for(int i = 1; i <= n; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }

    int cnt = 0; // 연결 요소(덩어리)의 개수

    // 모든 정점을 하나씩 확인하며 탐색 시작
    for(int i = 1; i <= n; i++)
    {
        // 아직 어느 덩어리에도 속하지 않은 정점을 발견하면?
        if(!visited[i])
        {
            bfs(i, graph, visited); // 해당 정점을 시작으로 덩어리 전체 방문
            cnt += 1; // 덩어리 개수 카운트
        }
    }

    cout << cnt << "\n";
    return 0;
}