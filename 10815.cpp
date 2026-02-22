#include <iostream>
#include <algorithm>
using namespace std;

// 이분 탐색 함수: 정렬된 배열에서 target의 존재 여부를 파악
int binary_search(long card[], long target, int start, int end)
{
    // 탐색 범위가 역전되면 찾는 값이 없는 것이므로 0 반환
    if(start > end)
    {
        return 0;
    }
    
    int mid = (start + end) / 2;
    
    // 값을 찾은 경우 1 반환
    if(card[mid] == target)
    {
        return 1;
    }
    // 중간값이 타겟보다 크면 왼쪽 구간(작은 쪽) 탐색
    else if(card[mid] > target)
    {
        return binary_search(card, target, start, mid - 1);
    }
    // 중간값이 타겟보다 작으면 오른쪽 구간(큰 쪽) 탐색
    else
    {
        return binary_search(card, target, mid + 1, end);
    }
}

int main()
{
    // 입출력 속도 향상을 위한 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 1. 상근이가 가진 카드 개수와 데이터 입력
    int n;
    cin >> n;
    long card[500001] = {0,};
    for (int i = 0; i < n; i++)
    {
        cin >> card[i];
    }
    
    // 이분 탐색을 위한 필수 작업: 배열 정렬
    sort(card, card + n);

    // 2. 확인할 카드의 개수 M 입력
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        long target;
        cin >> target;
        
        // 각 타겟마다 이분 탐색을 수행하여 결과 출력
        int result = binary_search(card, target, 0, n - 1);
        cout << result << " ";
    }
    
    return 0;
}