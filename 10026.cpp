#include <iostream>
#include <string>
#include <queue>
using namespace std;

// 최대 100x100 크기의 색상 지도와 방문 배열 전역 선언
char map[100][100]={'0',};
bool visited[100][100]={false,};

/**
 * BFS: 현재 칸과 같은 색상의 영역을 탐색함
 * 탐색 과정에서 'G'를 'R'로 변경하여 적록색약용 맵으로 실시간 변환
 */
void bfs(int y,int x, int n)
{
    queue<pair<int,int>> q;
    visited[y][x]=true;
    q.push({y,x});
    
    while(!q.empty())
    {
        pair<int,int> curr=q.front();
        int y=curr.first;
        int x=curr.second;
        
        // 상하좌우 탐색 방향 벡터
        int dy[4]={-1,1,0,0};
        int dx[4]={0,0,-1,1};
        q.pop();
        
        for(int i=0; i<4; i++)
        {
            int ny=y+dy[i];
            int nx=x+dx[i];
            
            // 1. 범위 내에 있고 && 2. 방문 전이며 && 3. 현재 칸과 색이 같은 경우 탐색
            if(ny>=0&&ny<n&&nx>=0&&nx<n&&!visited[ny][nx]&&(map[ny][nx]==map[y][x]))
            {
                visited[ny][nx]=true;
                q.push({ny,nx});
            }
            
            // 핵심 센스: 첫 번째 BFS 탐색 시 'G'를 'R'로 미리 바꿔둠 (적록색약용 전처리)
            // i==3 조건으로 4방향 확인이 끝난 시점에 현재 칸의 색상을 변경함
            if(i==3)
            {
                if(map[y][x]=='G')
                {
                    map[y][x]='R';
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
    
    int n;
    cin>>n;
    
    // 1. 그림 정보 입력
    for(int i=0; i<n; i++)
    {
        string color;
        cin>>color;
        for(int j=0; j<n; j++)
        {
            map[i][j]=color[j];
        }
    }
    
    // 2. 일반인 기준 영역 개수 탐색 (result1)
    int result1=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(!visited[i][j])
            {
                bfs(i,j,n); // 탐색하면서 G는 R로 바뀜
                result1++;
            }
        }
    }
    
    // 3. 방문 배열 초기화 (적록색약 탐색을 위해)
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            visited[i][j]=false;
        }
    
    // 4. 적록색약 기준 영역 개수 탐색 (result2)
    // 이전 BFS에서 G가 모두 R로 바뀌었으므로, R과 G를 같은 영역으로 인식하게 됨
    int result2=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(!visited[i][j])
            {
                bfs(i,j,n);
                result2++;
            }
        }
    }
    
    // 5. 일반인 결과와 적록색약 결과 출력
    cout<<result1<<" "<<result2<<"\n";
    
    return 0;
}