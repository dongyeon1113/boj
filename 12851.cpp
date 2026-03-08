#include <iostream>
#include <queue>
using namespace std;

// 최대 위치가 100,000이므로 100001 크기로 배열 선언
bool visited[100001]={false,}; // 해당 위치를 방문했는지 체크하는 배열
int dist[100001]={0,};         // 해당 위치까지 도달하는 '최단 시간(거리)'을 저장하는 배열
int cnt[100001]={0,};          // 해당 위치까지 '최단 시간으로 도달하는 방법의 수'를 저장하는 배열

void bfs(int n)
{
    queue<int> q;
    q.push(n);
    visited[n]=true; // 시작점 방문 처리
    cnt[n]=1;        // 시작점(수빈이의 첫 위치)까지 가는 경우의 수는 1가지로 초기화

    while(!q.empty())
    {
        int curr=q.front();
        q.pop();
        

        // 순간이동(curr * 2)을 처리하기 위해 배열에 curr 자체를 넣음
      
        int dx[3]={curr,-1,1}; 
        
        for(int i=0; i<3; i++)
        {
            int nx=curr+dx[i]; // 다음으로 이동할 위치 계산 (순간이동, 뒤로 걷기, 앞으로 걷기)
            
            // 맵의 범위(0 ~ 100,000)를 벗어나지 않는지 확인
            if(nx>=0 && nx<=100000)
            {
                // 케이스 1: 한 번도 방문한 적 없는 새로운 위치일 때
                if(!visited[nx])
                {
                    visited[nx]=true;           // 방문 처리
                    dist[nx]=dist[curr]+1;      // 이전 위치 시간 + 1초 기록
                    cnt[nx]=cnt[curr];          // 이전 위치까지 온 경우의 수를 그대로 물려받음
                    q.push(nx);                 // 큐에 넣어서 다음 탐색에 사용
                }
                // 케이스 2: 이미 방문했던 곳이지만, '똑같은 최단 시간'으로 도착한 또 다른 경로일 때
                else if(dist[nx]==dist[curr]+1)
                {
                    cnt[nx]+=cnt[curr];         // 새로운 경로를 찾았으므로 경우의 수를 누적(+=)해줌
                    // (주의: 이미 큐에 들어가 있거나 탐색된 곳이므로 큐에 또 넣지 않음)
                }
            }
        }
    }
}

int main()
{
   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,k;
    cin>>n>>k; // 수빈이 위치(n)와 동생 위치(k) 입력

    bfs(n); // BFS 탐색 시작
    
    // 결과 출력
    cout<<dist[k]<<"\n"; // 동생을 찾는 가장 빠른 시간
    cout<<cnt[k]<<"\n";  // 가장 빠른 시간으로 찾는 방법의 수
    
    return 0;
}