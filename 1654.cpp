#include <iostream>
#include <algorithm>
using namespace std;

// N개 이상의 랜선을 만들 수 있는 '최대' 길이를 저장하기 위한 변수
long long ans = 0;

/**
 * 이분 탐색을 통해 최적의 랜선 길이를 찾는 함수
 * @param lan: 이미 가지고 있는 랜선들의 길이 배열
 * @param target: 만들어야 하는 랜선의 개수 (N)
 * @param k: 가지고 있는 랜선의 개수 (K)
 * @param start: 탐색 범위의 시작 (최소 길이 1)
 * @param end: 탐색 범위의 끝 (랜선 중 가장 긴 길이)
 */
long long binary_search(long lan[], long long target, int k, long long start, long long end)
{
    // 탐색 범위가 역전되면 최종적으로 기록된 ans(최댓값)를 반환
    if (start > end)
    {
        return ans;
    }

    // 중간값(자를 랜선의 길이) 계산
    long long mid = (start + end) / 2;
    
    // 0으로 나누는 에러(Division by Zero) 방지
    if (mid == 0) mid = 1;

    long long sum = 0; // 잘린 랜선 조각들의 총 개수
    for (int i = 0; i < k; i++)
    {
        // 각 랜선을 mid 길이로 잘랐을 때 나오는 조각 수 합산
        sum += (lan[i] / mid);
    }

    // [핵심 로직] 개수가 목표(target)보다 많거나 같은 경우
    if (sum >= target) 
    {
        // 현재 길이(mid)로 N개 이상을 만들 수 있으므로 '일단 성공'
        ans = mid; 
        // 더 길게 자를 수 있는지 확인하기 위해 오른쪽 구간(큰 쪽) 탐색
        return binary_search(lan, target, k, mid + 1, end);
    }
    // 개수가 부족한 경우: 더 짧게 잘라서 조각 수를 늘려야 함
    else
    {
        // 왼쪽 구간(작은 쪽) 탐색
        return binary_search(lan, target, k, start, mid - 1);
    }
}

int main()
{
    // C++ 표준 입출력 성능 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    long long n;
    cin >> k >> n;

    // 랜선 길이 입력 (최대 10,000개)
    long lan[10001] = {0,};
    for (int i = 0; i < k; i++)
    {
        cin >> lan[i];
    }

    // 탐색 범위를 정하기 위해 오름차순 정렬 (가장 긴 랜선이 끝값)
    sort(lan, lan + k);

    // 1부터 가장 긴 랜선의 길이 사이에서 최적의 길이를 탐색
    long long result = binary_search(lan, n, k, 1, lan[k - 1]);
    
    // 최종 결과 출력
    cout << result << "\n";

    return 0;
}