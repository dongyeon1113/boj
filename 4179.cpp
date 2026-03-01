#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// 최대 1000x1000 미로와 각각의 방문/시간 기록 배열
char maze[1000][1000]={0,};
bool firevisited[1000][1000]={false,}; // 불 방문 여부
bool jhvisited[1000][1000]={false,};   // 지훈 방문 여부
int firecnt[1000][1000]={0,};          // 불이 각 칸에 도달하는 시간
int jhcnt[1000][1000]={0,};            // 지훈이가 각 칸에 도달하는 시간

/**
 * 불 전용 BFS: 불이 각 빈 공간('.')에 도달하는 최소 시간을 미리 계산
 */
void fire_bfs(queue<pair<int,int>> &q, int r, int c)
{
    while(!q.empty())
    {
        pair<int,int> curr=q.front();
        q.pop();
        int y=curr.first;
        int x=curr.second;
        int dy[4]={-1,1,0,0};
        int dx[4]={0,0,-1,1};
        
        for(int i=0; i<4; i++)
        {
            int ny=y+dy[i];
            int nx=x+dx[i];
            
            // 미로 범위 내, 방문 전, 그리고 빈 공간인 경우만 불이 번짐
            if(ny>=0&&ny<r&&nx>=0&&nx<c&&!firevisited[ny][nx]&&maze[ny][nx]=='.')
            {
                firevisited[ny][nx]=true;
                firecnt[ny][nx]=firecnt[y][x]+1;
                q.push({ny,nx});
            }
        }
    }
}

/**
 * 지훈 전용 BFS: 지훈이가 불보다 빨리 도달할 수 있는 칸만 골라서 이동
 */
void jh_bfs(int y,int x,int r, int c)
{
    queue<pair<int,int>> q;
    q.push({y,x});
    jhvisited[y][x]=true;
    
    while(!q.empty())
    {
        pair<int, int> curr=q.front();
        q.pop();
        int y=curr.first;
        int x=curr.second;
        int dy[4]={-1,1,0,0};
        int dx[4]={0,0,-1,1};
        
        for(int i=0; i<4; i++)
        {
            int ny=y+dy[i];
            int nx=x+dx[i];
            
            // 1. 범위 내, 방문 전, 빈 공간 확인
            // 2. 핵심 조건: 지훈이가 도착할 시간(jhcnt[y][x]+1)이 불이 도착할 시간(firecnt[ny][nx])보다 빨라야 함
            // 3. 단, 불이 아예 안 오는 곳(firecnt == 0)도 갈 수 있음
            if(ny>=0&&ny<r&&nx>=0&&nx<c&&!jhvisited[ny][nx]&&maze[ny][nx]=='.' &&
               ((jhcnt[y][x]+1 < firecnt[ny][nx]) || firecnt[ny][nx]==0))
            {
                jhvisited[ny][nx]=true;
                jhcnt[ny][nx]=jhcnt[y][x]+1;
                q.push({ny,nx});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int r,c;
    cin>>r>>c;
    
    queue<pair<int,int>> fire_q;
    int jy, jx;
    
    for(int i=0; i<r; i++)
    {
        string row;
        cin>>row;
        for(int j=0; j<c; j++)
        {
            maze[i][j]=row[j];
            if(maze[i][j]=='F') // 불의 위치들을 큐에 미리 삽입
            {
                fire_q.push({i,j});
                firevisited[i][j]=true;
            }
            else if(maze[i][j]=='J') // 지훈이 시작 위치 저장
            {
                jy=i; jx=j;
            }
        }
    }
    
    // 1단계: 불이 번지는 시간을 먼저 다 계산해둔다
    fire_bfs(fire_q,r,c);
    // 2단계: 그 시간을 참고해서 지훈이가 탈출 가능한지 계산한다
    jh_bfs(jy,jx,r,c);

    vector<int> result;
    bool flag=false; // 시작하자마자 가장자리에 있는 특수 경우 체크용
    
    // 3단계: 미로의 가장자리(탈출구)를 돌며 탈출 성공 여부 확인
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(i==0||i==r-1||j==0||j==c-1)
            {
                // 지훈이가 가장자리에 도달했다면 탈출 후보
                if(jhcnt[i][j]>0)
                {
                    result.push_back(jhcnt[i][j]);
                }
                // 시작점이 이미 가장자리인 경우
                if(maze[i][j]=='J')
                {
                    flag=true;
                    break;
                }
            }
        }
        if(flag) break;
    }
    
    sort(result.begin(),result.end());
    
    if(flag) // 시작부터 출구면 1초만에 탈출
    {
        cout<<1<<"\n";
    }
    else {
        if(result.empty()) // 가장자리에 도달한 기록이 없으면 탈출 실패
        {
            cout<<"IMPOSSIBLE"<<"\n";
        }
        else // 가장 빠른 탈출 시간 + 1 (밖으로 나가는 시간 포함)
        {
            cout<<result[0]+1<<"\n";
        }
    }
    
    return 0;
}