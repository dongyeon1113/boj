#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/**
 * BFS (너비 우선 탐색) - While문 정석 방식
 * 특징: 재귀 호출을 사용하지 않아 스택 오버플로우 위험이 없고, 
 * 레벨 단위(너비)로 탐색하므로 '최단 거리'를 구할 때 가장 유리함.
 */
void bfs(int start, vector<vector<int>> &graph, vector<bool> &visited)
{
    queue<int> q;
    
    // 1. 시작 노드를 큐에 넣고 방문 처리
    q.push(start);
    visited[start] = true;

    // 2. 큐가 빌 때까지 반복 (너비 우선 탐색의 핵심 루프)
    while(!q.empty())
    {
        int curr = q.front(); // 현재 조사할 노드 꺼내기
        q.pop();

        // 3. 현재 노드와 연결된 모든 인접 노드를 순회
        for(int i = 0; i < graph[curr].size(); i++)
        {
            int next = graph[curr][i];

            // 4. 아직 방문하지 않은 노드라면 큐에 넣고 방문 도장 찍기
            if(!visited[next])
            {
                visited[next] = true; 
                q.push(next); // 다음에 이 노드의 인접 노드들도 확인하기 위해 큐에 삽입
            }
        }
    }
}

int main()
{   
    // 입출력 속도 향상 (Fast I/O)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m; // 컴퓨터 수, 연결된 쌍의 수
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    vector<bool> visited(n + 1, false);
    
    // 그래프 정보 입력 (인접 리스트 생성)
    for(int i = 0; i < m; i++)
    {
        int a1, a2;
        cin >> a1 >> a2;
        
        // 양방향 연결 (바이러스는 양쪽으로 퍼지니까!)
        graph[a1].push_back(a2);
        graph[a2].push_back(a1);
    }

    // 인접 노드를 번호 순으로 탐색하기 위해 정렬 (문제 조건에 따라 필요)
    for(int i = 1; i <= n; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }

    // 1번 컴퓨터가 바이러스에 걸림
    bfs(1, graph, visited);

    // 1번을 제외하고 방문(감염)된 컴퓨터 수 계산
    int cnt = 0;
    for(int i = 2; i <= n; i++)
    {
        if(visited[i])
        {
            cnt += 1;
        }
    }

    cout << cnt << "\n";

    return 0;
}