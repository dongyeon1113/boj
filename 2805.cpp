#include <iostream>
#include <algorithm>
using namespace std;

// 정답을 저장할 전역 변수: 적어도 M미터를 가져갈 수 있는 높이 중 최댓값을 기록
long ans = 0;

int binary_search(long tree[], long n, long target, long start, long end)
{
    // 탐색 범위가 역전되면 최종적으로 저장된 최적의 정답(ans)을 반환
    if(start > end)
    {
        return ans;
    }

    long mid = (start + end) / 2; // 절단기의 높이 설정
    
    long long sum = 0; // 나무 조각들의 합 (최대 100만 * 10억이므로 long long 필수)
    for (int i = 0; i < n; i++)
    {
        // 현재 설정한 높이(mid)보다 나무가 높을 때만 잘린 조각을 합산
        if(tree[i] >= mid)
        {
            sum += (tree[i] - mid);
            continue;
        }
    }

    // 1. 딱 필요한 만큼 자른 경우: 이 높이가 최적이므로 바로 반환
    if(sum == target)
    {
        return mid;
    }
    // 2. 나무가 필요한 것보다 많이 남는 경우: 
    // 일단 현재 높이를 정답 후보(ans)에 저장하고, 높이를 더 높여서 더 효율적인 값을 찾아본다.
    else if(sum > target)
    {
        ans = mid; 
        return binary_search(tree, n, target, mid + 1, end);
    }
    // 3. 나무가 모자란 경우: 절단기 높이를 낮춰서 더 많이 잘라야 함
    else
    {
        return binary_search(tree, n, target, start, mid - 1);
    }
}

int main()
{
    // 입출력 성능 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long n, m;
    cin >> n >> m;

    // 나무의 개수는 최대 1,000,000개
    long tree[1000001] = {0,};
    for (int i = 0; i < n; i++)
    {
        cin >> tree[i];
    }

    // 이분 탐색의 범위 설정을 위해 나무 높이 정렬 (0부터 가장 높은 나무까지가 탐색 범위)
    sort(tree, tree + n);

    // 0(최소 높이)부터 tree[n-1](최대 나무 높이) 사이에서 이분 탐색 시작
    int result = binary_search(tree, n, m, 0, tree[n - 1]);
    
    cout << result << "\n";

    return 0;
}