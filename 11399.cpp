#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    int time[1001] = {0,};
    for(int i = 0; i < n; i++)
    {
        cin >> time[i];
    }

    // [핵심] 오름차순 정렬: 인출 시간이 짧은 사람을 앞에 세워야 
    // 뒤에 기다리는 사람들의 누적 대기 시간이 최소가 됨 (Greedy)
    sort(time, time + n);

    int total_sum = 0; // 모든 사람이 기다린 시간의 총합
    int current_wait = 0; // 현재 순서인 사람이 대기한 시간 (앞사람들의 합)

    for(int i = 0; i < n; i++)
    {
        // 총합 = (이전까지 대기한 시간 + 내가 인출하는 시간)을 계속 더함
        total_sum += (current_wait + time[i]);
        
        // 다음 사람이 대기해야 할 시간 갱신
        current_wait += time[i];
    }

    cout << total_sum << "\n";

    return 0;
}