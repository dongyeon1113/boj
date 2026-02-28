#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/**
 * DFS (깊이 우선 탐색): 재귀 호출을 이용한 탐색
 * 원리: 현재 노드에서 갈 수 있는 한 방향을 끝까지 파고든 뒤, 
 * 더 이상 갈 곳이 없으면(함수 종료) 이전 분기점으로 돌아와 옆길을 찾음.
 */
void dfs(int v, vector<vector<int>> graph, vector<bool> &visited, vector<int> &result)
{
    // 현재 노드(v)와 연결된 모든 인접 노드를 확인
    for(int i = 0; i < graph[v].size(); i++)
    {
        int next = graph[v][i];
        if(!visited[next]) // 아직 방문하지 않은 노드라면
        {
            visited[next] = true;      // 방문 체크
            result.push_back(next);    // 결과 경로에 추가
            dfs(next, graph, visited, result); // 즉시 더 깊은 단계로 재귀 호출
        }
    }
}

/**
 * BFS (너비 우선 탐색): 큐와 재귀를 이용한 탐색
 * 원리: 인접한 형제 노드들을 먼저 모두 큐에 넣고 방문한 뒤, 
 * 큐의 앞부분부터 꺼내어 그 다음 레벨의 자식들을 탐색함.
 */
void bfs(int v, vector<vector<int>> graph, vector<bool> &visited, vector<int> &result, queue<int> &q)
{
    // 1. 현재 노드(v)의 모든 인접 노드를 먼저 '방문 처리'하고 큐에 삽입 (너비 우선)
    for(int i = 0; i < graph[v].size(); i++)
    {   
        int next = graph[v][i];
        if(!visited[next])
        {
            visited[next] = true;
            result.push_back(next);
            q.push(next);
        }
    }

    // 2. 큐가 빌 때까지 반복하며 다음 레벨의 노드들을 순차적으로 방문
    if(!q.empty())
    {
        int next_v = q.front();
        q.pop();
        bfs(next_v, graph, visited, result, q); // 큐에서 꺼낸 다음 노드로 이동
    }
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, v; // 정점 개수, 간선 개수, 시작 노드
    cin >> n >> m >> v;

    vector<vector<int>> graph(n + 1);
    vector<bool> visited_dfs(n + 1, false);
    vector<bool> visited_bfs(n + 1, false);
    vector<int> dfs_result;
    vector<int> bfs_result;
    queue<int> q;

    // 인접 리스트 방식으로 그래프 구현
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // 번호가 낮은 노드부터 방문하기 위해 오름차순 정렬
    for(int i = 1; i <= n; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }

    // 시작 노드 설정 및 초기 방문 처리
    visited_dfs[v] = true;
    visited_bfs[v] = true;
    dfs_result.push_back(v);
    bfs_result.push_back(v);

    // 탐색 시작
    dfs(v, graph, visited_dfs, dfs_result);
    bfs(v, graph, visited_bfs, bfs_result, q);

    // DFS 결과 출력
    for(int i = 0; i < dfs_result.size(); i++)
    {
        cout << dfs_result[i] << " ";
    }
    cout << "\n";

    // BFS 결과 출력
    for(int i = 0; i < bfs_result.size(); i++)
    {
        cout << bfs_result[i] << " ";
    }

    return 0;
}