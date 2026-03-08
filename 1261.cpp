#include <iostream>
#include <deque>
#include <string>
#include <tuple>
using namespace std;

// 최대 100x100 크기의 미로 맵, 방문 여부, 벽 부순 횟수를 저장할 배열
int map[100][100] = {0,};
bool visited[100][100] = {false,};
int broken_cnt[100][100] = {0,};

// 0-1 BFS를 이용하여 최소 벽 부수기 횟수를 구하는 함수
void bfs(int n, int m)
{
    // 튜플: {y좌표, x좌표, 부순 벽의 개수}
    deque<tuple<int,int,int>> dq;
    
    // 시작점 (0, 0) 세팅: 부순 벽의 개수는 0
    dq.push_back({0, 0, 0});
    int result = 0;
    visited[0][0] = true;
    
    while(!dq.empty())
    {
        // 덱의 맨 앞에서 현재 상태를 꺼냄
        tuple<int,int,int> curr = dq.front();
        dq.pop_front();
        int y = get<0>(curr);
        int x = get<1>(curr);
        int cnt = get<2>(curr);
        
        // 상하좌우 탐색을 위한 방향 배열
        int dy[4] = {-1, 1, 0, 0};
        int dx[4] = {0, 0, -1, 1};
        
        for(int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            // 미로 범위를 벗어나지 않고, 아직 방문하지 않은 칸일 경우
            if(ny >= 0 && ny < n && nx >= 0 && nx < m && !visited[ny][nx])
            {
                // 다음 칸이 벽(1)인 경우 (가중치 1)
                if(map[ny][nx] == 1)
                {
                    // 벽을 부숴야 하므로 부순 횟수(cnt)를 1 증가시키고 덱의 '뒤(back)'에 삽입
                    dq.push_back({ny, nx, cnt + 1});
                    visited[ny][nx] = true;
                    broken_cnt[ny][nx] = cnt + 1; // 해당 위치까지 최소로 부순 벽의 수 기록
                }
                // 다음 칸이 빈 방(0)인 경우 (가중치 0)
                else
                {
                    // 비용이 0이므로 우선적으로 탐색하기 위해 덱의 '앞(front)'에 삽입
                    dq.push_front({ny, nx, cnt});
                    visited[ny][nx] = true;
                    broken_cnt[ny][nx] = cnt;     // 부순 횟수 증가 없이 그대로 기록
                }
            }
        }
    }
}

int main()
{
    // C++ 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int m, n;
    // m: 가로 크기(열 개수), n: 세로 크기(행 개수)
    cin >> m >> n;
    
    // 미로 맵 정보 입력 (공백 없이 주어지므로 string으로 받아서 처리)
    for(int i = 0; i < n; i++)
    {
        string row;
        cin >> row;
        for(int j = 0; j < m; j++)
        {
            // 문자를 숫자로 변환하여 배열에 저장
            map[i][j] = row[j] - '0';
        }
    }
    
    // 0-1 BFS 탐색 실행
    bfs(n, m);
    
    /* // 디버깅용: 각 칸까지 도달하기 위해 부순 최소 벽의 개수 출력
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout<<broken_cnt[i][j]<<" ";
        }
        cout<<"\n";
    }
    */
    
    // 도착점 (n-1, m-1)에 도달하기 위해 부순 최소 벽의 개수 출력
    cout << broken_cnt[n-1][m-1] << "\n";
    
    return 0;
}