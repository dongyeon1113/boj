#include <iostream>
#include <vector>
#include <queue>
#include <cstring> // memset 사용을 위해 필요한 헤더
using namespace std;

// 전역 변수: 배추밭(map)과 방문 기록(visited)
int map[50][50]={0,};
bool visited[50][50]={false,};

/**
 * BFS 함수: (x, y) 좌표에서 인접한 모든 배추(1)를 방문 처리함
 */
void bfs(int x, int y, int m, int n)
{
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y]=true;
    while(!q.empty())
    {
        pair<int,int> curr=q.front();
        q.pop();

        int x=curr.first;
        int y=curr.second;
        
        // 상하좌우 탐색을 위한 방향 벡터
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        
        for(int i=0; i<4; i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];
            
            // 1. 배추밭 범위(M x N) 안에 있는지 확인
            if(nx>=0&&nx<m&&ny>=0&&ny<n)
            {
                // 2. 방문하지 않았고, 배추(1)가 심어진 곳이라면 큐에 추가
                if(!visited[nx][ny]&&map[nx][ny]==1)
                {
                    visited[nx][ny]=true;
                    q.push({nx,ny});
                }
            }
        }
    }
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t,m,n,k;
    cin>>t; // 테스트 케이스 개수 입력
    
    for(int i=0; i<t; i++)
    {
        // 핵심: 다음 테스트 케이스를 위해 이전 데이터(map, visited)를 모두 0/false로 초기화
        memset(map,0,sizeof(map));
        memset(visited,false,sizeof(visited));
        
        cin>>m>>n>>k; // 가로, 세로, 배추 개수 입력
        int cnt=0;    // 필요한 지렁이 수 초기화
        
        // k개의 배추 위치 정보를 받아 지도에 표시
        for(int i=0; i<k; i++)
        {
            int x,y;
            cin>>x>>y;
            map[x][y]=1;
        }
        
        // 지도를 전체 순회하며 새로운 배추 덩어리 탐색
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                // 배추가 있고 아직 방문 전이면, 새로운 지렁이 한 마리가 필요함
                if(map[i][j]==1 && !visited[i][j])
                {
                    bfs(i,j,m,n); // 연결된 모든 배추 방문 처리
                    cnt+=1;       // 지렁이 마리수 증가
                }
            }
        }
        cout<<cnt<<"\n"; // 현재 판에 필요한 총 지렁이 수 출력
    }
    
    return 0;
}