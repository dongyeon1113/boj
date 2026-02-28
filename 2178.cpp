#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

// 전역 변수: 최대 100x100 크기 미로와 방문 배열
int map[100][100]={0,};
bool visited[100][100]={false,};

/**
 * BFS: (0,0)에서 시작하여 각 칸까지의 최단 거리를 map에 직접 기록함
 */
void bfs(int x,int y, int n, int m)
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
        
        // 상하좌우 탐색을 위한 방향 설정
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        
        for(int i=0; i<4; i++)
        {
            int nx=dx[i]+x;
            int ny=dy[i]+y;
            
            // 1. 미로 범위 내에 있는지 확인
            if(nx>=0&&nx<n&&ny>=0&&ny<m)
            {
                // 2. 방문하지 않았고, 갈 수 있는 길(1)인지 확인
                if(!visited[nx][ny]&&map[nx][ny]==1)
                {
                    visited[nx][ny]=true;
                    q.push({nx,ny});
                    
                    // 핵심: 다음 칸의 숫자를 '현재 칸 숫자 + 1'로 업데이트하여 거리를 기록
                    map[nx][ny]=map[x][y]+1;
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
    
    int n,m;
    cin>>n>>m;
    
    // 미로 입력 처리: 붙어서 들어오는 숫자를 string으로 받아 하나씩 숫자로 변환
    for(int i=0; i<n; i++)
    {
        string row;
        cin>>row;
        for(int j=0; j<m; j++)
        {
            map[i][j]=row[j]-'0';
        }
    }
    
    // (0, 0) 좌표부터 BFS 탐색 시작
    bfs(0,0,n,m);
    
    // 최종 목적지 (n-1, m-1)에 저장된 최단 거리 값 출력
    cout<<map[n-1][m-1]<<"\n";
    
    return 0;
}