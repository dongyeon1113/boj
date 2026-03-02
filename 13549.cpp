#include <iostream>
#include <deque>
using namespace std;

// 최대 위치 100,000까지의 방문 여부 및 시간 저장
bool visited[100001] = {false,};
int dist[100001] = {0,};

/**
 * 0-1 BFS: 가중치가 0인 이동은 덱의 앞(front)에, 1인 이동은 뒤(back)에 삽입
 */
void bfs(int n)
{
    deque<int> q;
    q.push_back(n);
    visited[n] = true;
    
    while(!q.empty())
    {
        int curr = q.front();
        q.pop_front();
        
        // 3가지 이동 방식: 1.순간이동(0초), 2.뒤로걷기(1초), 3.앞으로걷기(1초)
        // dx[0]이 curr이므로 curr + dx[0]은 curr * 2가 됨
        int dx[3] = {curr, -1, 1}; 
        
        for(int i=0; i<3; i++)
        {
            int next = curr + dx[i];
            
            // 수직선 범위 내에 있고 아직 방문하지 않은 위치라면
            if(next >= 0 && next <= 100000 && !visited[next])
            {
                // 1. 순간이동인 경우 (i == 0)
                if(i == 0)
                {
                    visited[next] = true;
                    // 가중치가 0이므로 덱의 맨 앞에 넣어 우선순위를 높임
                    q.push_front(next);
                    // 시간은 이전 위치와 동일 (0초 추가)
                    dist[next] = dist[curr];
                }
                // 2. 걷는 경우 (i == 1, 2)
                else
                {
                    visited[next] = true;
                    // 가중치가 1이므로 덱의 맨 뒤에 넣음
                    q.push_back(next);
                    // 시간 1초 추가
                    dist[next] = dist[curr] + 1;
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
    
    int n, k;
    cin >> n >> k;
    
    // BFS 탐색 시작
    bfs(n);
    
    // 동생 위치 k까지의 최단 시간 출력
    cout << dist[k] << "\n";
    
    return 0;
}