#include <iostream>
#include <queue>
#include <tuple> // 3개의 좌표(z, y, x)를 묶기 위해 사용
using namespace std;

// 최대 100x100x100 크기의 3차원 토마토 창고 선언
int tomato[100][100][100]={0,};

/**
 * 3D BFS: 큐에 담긴 모든 익은 토마토들이 상/하/좌/우/위/아래 6방향으로 동시 탐색
 */
void bfs(queue<tuple<int,int,int>> &q, int h, int n, int m)
{
    while(!q.empty())
    {
        tuple<int,int,int> curr=q.front();
        q.pop();

        // tuple에서 각 좌표 추출: get<인덱스>(변수명)
        int z=get<0>(curr); // 높이
        int y=get<1>(curr); // 세로
        int x=get<2>(curr); // 가로

        // 3차원 6방향 탐색을 위한 방향 벡터 (위, 아래, 앞, 뒤, 좌, 우)
        int dz[6]={-1,1,0,0,0,0};
        int dy[6]={0,0,-1,1,0,0};
        int dx[6]={0,0,0,0,-1,1};

        for(int i=0; i<6; i++)
        {
            int nz=z+dz[i];
            int ny=y+dy[i];
            int nx=x+dx[i];

            // 1. 3차원 공간 범위 체크 (높이 h, 세로 n, 가로 m)
            if(nz>=0&&nz<h&&ny>=0&&ny<n&&nx>=0&&nx<m)
            {
                // 2. 아직 익지 않은 토마토(0)인 경우만 익힘 처리
                if(tomato[nz][ny][nx]==0)
                {
                    // 이전 토마토 날짜 + 1 기록
                    tomato[nz][ny][nx]=tomato[z][y][x]+1;
                    q.push({nz,ny,nx});
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

    int m,n,h;
    cin>>m>>n>>h; // m:가로, n:세로, h:높이

    // 1. 3차원 배열 입력 (높이 -> 세로 -> 가로 순서)
    for(int k=0; k<h; k++)
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
            {
                cin>>tomato[k][i][j];
            }
     
    // 2. 익은 토마토(1)들을 모두 찾아 큐에 삽입 (시작점들)
    queue<tuple<int,int,int>> q;
    for(int k=0; k<h; k++)
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
            {
                if(tomato[k][i][j]==1)
                {
                    q.push({k,i,j});
                }
            }

    // 3. BFS 실행
    bfs(q,h,n,m);
    
    int result=0;
    bool flag=true; // 모두 익었는지 판별할 플래그

    // 4. 결과 확인: 전체 공간을 돌며 최댓값 찾기 및 미익 토마토 체크
    for(int k=0; k<h; k++)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                // 가장 큰 숫자(마지막에 익은 날짜) 갱신
                if(tomato[k][i][j]>result)
                {
                    result=tomato[k][i][j];
                }
                // 하나라도 익지 않은 토마토(0)가 남아있다면 실패
                else if(tomato[k][i][j]==0)
                {
                    flag=false;
                }
            }
        }
    }

    // 5. 최종 출력
    if(flag)
    {
        // 시작값이 1이었으므로 1을 빼야 실제 걸린 일수임
        cout<<result-1<<"\n";
    }
    else
    {
        // 익지 않은 토마토가 있으면 -1 출력
        cout<<-1<<"\n";
    }

    return 0;
}