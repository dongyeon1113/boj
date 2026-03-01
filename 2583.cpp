#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 최대 100x100 크기의 모눈종이와 방문 배열 선언
int map[100][100]={0,};
bool visited[100][100]={false,};

/**
 * BFS: 분리된 각 영역의 넓이를 계산하여 반환
 */
int bfs(int y, int x, int m, int n)
{
    queue<pair<int,int>> q;
    visited[y][x]=true;
    q.push({y,x});
    int cnt=1; // 영역의 넓이 (시작점 포함 1부터 시작)

    while(!q.empty())
    {
        pair<int,int> curr=q.front();
        q.pop();

        int y= curr.first;
        int x=curr.second;
        
        // 상하좌우 탐색 방향 벡터
        int dy[4]={-1,1,0,0};
        int dx[4]={0,0,-1,1};

        for(int i=0; i<4; i++)
        {
            int ny=dy[i]+y;
            int nx=dx[i]+x;

            // 1. 모눈종이 범위 체크 (M: 세로, N: 가로)
            if(ny>=0&&ny<m&&nx>=0&&nx<n)
            {
                // 2. 방문하지 않았고, 직사각형이 없는 빈 공간(0)인 경우
                if(!visited[ny][nx]&&map[ny][nx]==0)
                {
                    cnt++; // 넓이 증가
                    visited[ny][nx]=true;
                    q.push({ny,nx});
                }
            }
        }
    }
    return cnt; // 해당 영역의 총 넓이 반환
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m,n,k;
    cin>>m>>n>>k; // M: 세로(행), N: 가로(열), K: 직사각형 개수
    vector<int> result;

    // 1. K개의 직사각형 영역을 1로 채우기 (전처리)
    for(int i=0; i<k; i++)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        // 문제의 좌표 평면과 배열 인덱스는 상하가 뒤집혀 보일 수 있으나
        // 상대적인 영역 크기는 동일하므로 주어진 좌표 범위 그대로 채우면 됨
        for(int y=y1; y<y2; y++)
        {
            for(int x=x1; x<x2; x++)
            {
                map[y][x]=1; // 직사각형이 차지하는 공간은 1로 표시
            }
        }
    }

    /* 디버깅용: map 상태 확인 코드
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) cout<<map[i][j]<<" ";
        cout<<"\n";
    } */

    int cnt=0; // 분리된 영역의 개수
    // 2. 전체 모눈종이를 돌며 빈 공간(0) 발견 시 BFS 시작
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(map[i][j]==0 && !visited[i][j])
            {
                result.push_back(bfs(i,j,m,n)); // 영역 넓이 저장
                cnt+=1; // 영역 개수 증가
            }
        }
    }

    // 3. 결과 정렬 및 출력
    sort(result.begin(),result.end()); // 문제 요구사항: 넓이를 오름차순으로 정렬
    cout<<cnt<<"\n"; // 전체 영역 개수 출력

    for(int i=0; i<result.size(); i++)
    {
        cout<<result[i]<<" "; // 각 영역 넓이 출력
    }
    cout<<"\n";

    return 0;
}