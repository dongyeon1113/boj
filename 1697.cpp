#include <iostream>
#include <queue>
using namespace std;

// 최대 위치 100,000까지의 시간 기록 및 방문 확인 배열
int map[100001]={0,};
int cnt[100001]={0,};     // 각 위치까지 도달하는 데 걸린 최소 시간을 저장
bool visited[100001]={false,};

/**
 * BFS: 1차원 수직선 위에서 -1, +1, *2 이동을 하며 동생을 찾음
 */
void bfs(int n)
{
    queue<int> q;
    q.push(n);
    visited[n]=true;
    
    while(!q.empty())
    {
        int curr=q.front();
        q.pop();
        
        // 이동 가능한 3가지 변화량: 1.뒤로 한 칸, 2.앞으로 한 칸, 3.현재만큼 더 가기(2배)
        int d[3]={-1, 1, curr}; 
        
        for(int i=0; i<3; i++)
        {
            int next = curr + d[i]; // 다음 위치 계산
            
            // 1. 수직선 범위(0~100,000) 내에 있고 && 2. 아직 방문하지 않은 위치라면
            if(next >= 0 && next <= 100000 && !visited[next])
            {
                // 현재 위치까지 걸린 시간 + 1을 다음 위치에 저장
                cnt[next] = cnt[curr] + 1;
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k; // n: 수빈이 위치, k: 동생 위치
    
    // BFS 탐색 시작
    bfs(n);

    // 동생의 위치 k에 기록된 최소 시간 출력
    cout << cnt[k] << "\n";
    
    return 0;
}