#include <iostream>
#include <queue>
using namespace std;

// 최대 1000x1000 크기의 토마토 창고 전역 선언
int tomato[1000][1000]={0,};

/**
 * BFS: 큐에 미리 담긴 모든 익은 토마토(1)들을 시작점으로 동시에 탐색 진행
 */
void bfs(queue<pair<int,int>> &q, int m, int n)
{
    while(!q.empty())
    {
        pair<int,int> curr=q.front();
        q.pop();
        
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        int x=curr.first;
        int y=curr.second;
        
        for(int i=0; i<4; i++)
        {
            int nx=dx[i]+x;
            int ny=dy[i]+y;
            
            // 1. 창고 범위를 벗어나지 않고 && 2. 아직 익지 않은 토마토(0)인 경우만 탐색
            if(nx>=0&& nx<n && ny>=0 && ny< m && tomato[nx][ny]==0)
            {
                // 이전 토마토가 익은 날짜 + 1을 해서 거리(일수)를 기록
                tomato[nx][ny]=tomato[x][y]+1;
                q.push({nx,ny});
            }
        }
    }
}

int main()
{
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int m,n;
    cin>>m>>n; // m: 가로(열), n: 세로(행)
    
    // 1. 창고 정보 입력
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>tomato[i][j];
        }
    }
    
    // 2. 익은 토마토(1)를 모두 찾아 큐에 미리 삽입 (다중 시작점 설정)
    queue<pair<int,int>> q;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(tomato[i][j]==1)
            {
                q.push({i,j});
            }
        }
    }
    
    // 3. 탐색 시작: 모든 익은 토마토들이 동시에 주변을 익히기 시작함
    bfs(q,m,n);
    
    int result=0;
    bool flag=true; // 토마토가 모두 익었는지 확인하는 플래그
    
    // 4. 결과 도출: 전체 창고를 돌며 최댓값 찾기 및 익지 않은 토마토 체크
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            // 가장 늦게 익은 토마토의 날짜(최댓값) 갱신
            if(tomato[i][j]>result)
            {
                result=tomato[i][j];
            }
            // BFS가 끝났는데도 여전히 0이라면, 모두 익히는 것이 불가능한 경우임
            else if(tomato[i][j]==0)
            {
                flag=false;
            }
        }
    }
    
    // 5. 최종 출력
    if(!flag) // 익지 않은 토마토가 하나라도 있으면 -1
    {
        cout<<-1<<"\n";
    }
    else
    {
        // 시작 날짜를 1로 설정했으므로, 실제 경과일은 (최댓값 - 1)
        cout<<result-1<<"\n";
    }
    
    return 0;
}