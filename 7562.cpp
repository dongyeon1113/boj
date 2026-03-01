#include <iostream>
#include <queue>
using namespace std;

// 최대 300x300 크기의 체스판 방문 여부 및 이동 횟수 저장 배열
bool visited[300][300]={false,};
int cnt[300][300]={0,};

/**
 * BFS: 나이트의 이동 규칙(L자 8방향)에 따라 목표 지점까지의 최단 거리를 계산
 */
void bfs(int y, int x, int n)
{
    queue<pair<int,int>> q;
    visited[y][x]=true;
    q.push({y,x});
    
    while(!q.empty())
    {
        pair<int,int> curr=q.front();
        q.pop();
        
        int y=curr.first;
        int x=curr.second;
        
        // 나이트가 이동할 수 있는 8가지 방향 (L자 모양)
        int dy[8]={2, 1, -2, -1, 2, 1, -2, -1};
        int dx[8]={1, 2, 1, 2, -1, -2, -1, -2};
        
        for(int i=0; i<8; i++)
        {
            int ny=y+dy[i];
            int nx=x+dx[i];
            
            // 1. 체스판 범위 내에 있고 && 2. 아직 방문하지 않은 위치라면
            if(nx>=0 && nx<n && ny>=0 && ny<n && !visited[ny][nx])
            {
                visited[ny][nx]=true;
                q.push({ny,nx});
                // 이전 칸의 이동 횟수에 1을 더해 현재 칸까지의 거리 기록
                cnt[ny][nx]=cnt[y][x]+1;
            }
        }
    }
}

int main()
{
    // 입출력 성능 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t; // 테스트 케이스 개수
    
    for(int i=0; i<t; i++)
    {
        int n;
        cin>>n; // 체스판의 한 변의 길이
        
        // 중요: 새로운 테스트 케이스를 위해 배열 초기화
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
            {
                visited[i][j]=false;
                cnt[i][j]=0;
            }
            
        int y1, x1, y2, x2;
        cin>>y1>>x1; // 시작 위치
        cin>>y2>>x2; // 목표 위치
        
        // 시작 위치와 목표 위치가 같으면 0을 출력해야 하므로 BFS 전에 체크할 수도 있지만,
        // 현재 로직상 BFS를 돌려도 시작점의 cnt는 0이므로 결과는 정확함
        bfs(y1, x1, n);
        
        // 목표 위치에 기록된 최소 이동 횟수 출력
        cout<<cnt[y2][x2]<<"\n";
    }
    return 0;
}