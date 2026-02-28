#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
int map[25][25]={0,};
bool visited[25][25]={false,};

int bfs(int x, int y, int n)
{
    queue<pair<int,int>> q;
    q.push({x,y});
    int cnt=1; // 단지 내 집 개수를 저장할 변수 (시작점 포함 1부터 시작)
    visited[x][y]=true;
    
    while(!q.empty())
    {
        pair<int, int> curr=q.front();
        q.pop();
        
        int x=curr.first;  // 현재 방문 중인 x좌표
        int y=curr.second; // 현재 방문 중인 y좌표
        
        // 상하좌우 탐색을 위한 방향 벡터 설정
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        
        for(int i=0; i<4; i++)
        {
            int nx=x+dx[i]; // 다음에 확인할 x좌표
            int ny=y+dy[i]; // 다음에 확인할 y좌표
            
            // 1. 지도 경계 내에 있고 && 2. 아직 방문 전이며 && 3. 실제 집(1)이 있는 곳인지 확인
            if(((nx>=0 && nx<=n-1)&&(ny>=0 && ny<=n-1))&&!visited[nx][ny]&&map[nx][ny]==1)
            {
                q.push({nx,ny});      // 조건을 만족하면 큐에 삽입
                visited[nx][ny]=true;  // 방문 표시
                cnt+=1;               // 단지 내 집 개수 증가
            }
        }
    }
    return cnt; // 탐색이 완료된 단지의 총 집 개수 반환
}
int main()
{
    // C++ 입출력 속도 향상을 위한 설정
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> result;// 각 단지별 집 개수를 담을 벡터
    // 지도를 string으로 한 줄씩 입력받아 숫자로 변환하여 저장
    for(int i=0; i<n; i++)
    {
        string row;
        cin>>row;
        for(int j=0; j<n; j++)
        {
            map[i][j]=row[j]-'0';// 아스키 코드 차이를 이용해 정수 변환
        }
    }
    int cnt=0;// 발견된 총 단지 수
    // 이중 for문을 돌며 지도의 모든 칸을 확인
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            // 집이 존재하고 아직 방문하지 않은 새로운 단지 시작점을 찾으면 BFS 실행
            if(map[i][j]==1&&!visited[i][j])
            {
                result.push_back(bfs(i,j,n));// 단지의 크기를 결과 벡터에 저장
                cnt+=1;// 단지 개수 증가
            }
        }
    }
    cout<<cnt<<"\n";
    sort(result.begin(),result.end());
    for(int i=0; i<result.size(); i++)
    {
        cout<<result[i]<<"\n";
    }

}