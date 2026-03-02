#include <iostream>
#include <queue>
#include <tuple>
#include <string>
#include <algorithm>
using namespace std;

int map[1000][1000] = {0,};
// visited[y][x][0]: 벽 안 부수고 방문, visited[y][x][1]: 벽 하나 부수고 방문
bool visited[1000][1000][2] = {false,};
int dist[1000][1000][2] = {0,};

/**
 * BFS: 벽 파괴 기회(1회)를 상태값으로 가지고 탐색
 */
void bfs(int y, int x, int n, int m)
{
    // tuple<y, x, broken>: 좌표와 벽 파괴 여부(0: 안부숨, 1: 부숨) 저장
    queue<tuple<int,int,int>> q;
    q.push({y, x, 0});
    visited[y][x][0] = true;
    
    while(!q.empty())
    {
        tuple<int,int,int> curr = q.front();
        q.pop();
        
        int y = get<0>(curr);
        int x = get<1>(curr);
        int broken = get<2>(curr);
        
        int dy[4] = {-1, 1, 0, 0};
        int dx[4] = {0, 0, -1, 1};
        
        for(int i=0; i<4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny >= 0 && ny < n && nx >= 0 && nx < m)
            {
                // 1. 이동할 곳이 평지(0)인 경우
                if(map[ny][nx] == 0)
                {
                    // 현재 상태(broken) 그대로 방문한 적이 없다면 이동
                    if(!visited[ny][nx][broken])
                    {
                        visited[ny][nx][broken] = true;
                        dist[ny][nx][broken] = dist[y][x][broken] + 1;
                        q.push({ny, nx, broken});
                    }
                }
                // 2. 이동할 곳이 벽(1)이고, 아직 벽을 부순 적이 없는 경우(broken == 0)
                else if(map[ny][nx] == 1 && broken == 0)
                {
                    // 벽을 부순 세계([1])로 넘어가며 방문 처리
                    if(!visited[ny][nx][1])
                    {
                        visited[ny][nx][1] = true;
                        dist[ny][nx][1] = dist[y][x][broken] + 1;
                        q.push({ny, nx, 1}); // 이제부터 이 경로는 '벽 부순 상태'임
                    }
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    for(int i=0; i<n; i++)
    {
        string row;
        cin >> row;
        for(int j=0; j<m; j++)
        {
            map[i][j] = row[j] - '0';
        }
    }
    
    bfs(0, 0, n, m);
    
    // 결과 출력 로직
    // 1. 두 경로 모두 도달 가능한 경우: 더 작은 값 선택
    if(visited[n-1][m-1][0] && visited[n-1][m-1][1])
    {
        cout << min(dist[n-1][m-1][0], dist[n-1][m-1][1]) + 1 << "\n";
    }
    // 2. 두 경로 모두 도달 불가능한 경우: -1
    else if(!visited[n-1][m-1][0] && !visited[n-1][m-1][1])
    {
        cout << -1 << "\n";
    }
    // 3. 한쪽 경로로만 도달 가능한 경우: 도달한 쪽의 거리 출력 (max 이용)
    else {
        cout << max(dist[n-1][m-1][0], dist[n-1][m-1][1]) + 1 << "\n";
    }
    
    return 0;
}