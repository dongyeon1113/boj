#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 재귀 방식을 이용한 이분 탐색 함수
int binary_search(int data[], int target, int start, int end)
{
    // 탐색 범위가 역전되면 타겟이 없는 것이므로 0 반환
    if(start > end)
    {
        return 0;
    }
    
    int mid = (start + end) / 2;
    
    // 타겟을 찾은 경우 1 반환
    if(data[mid] == target)
    {
        return 1;
    }
    // 중간값이 타겟보다 크면 왼쪽 절반 탐색
    else if(data[mid] > target)
    {
        return binary_search(data, target, start, mid - 1);
    }
    // 중간값이 타겟보다 작으면 오른쪽 절반 탐색
    else {
        return binary_search(data, target, mid + 1, end);
    }
}

int main()
{
    // 입출력 속도 향상을 위한 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    // 탐색의 대상이 되는 데이터 배열 (최대 10만 개)
    int data[100001] = {0,};
    for (int i = 0; i < n; i++)
    {
        cin >> data[i];     
    }
    
    // 이분 탐색의 전제 조건: 데이터가 반드시 정렬되어 있어야 함
    sort(data, data + n);

    int m;
    cin >> m;
    
    // 확인할 타겟 숫자들 입력 및 즉시 탐색 실행
    int target[100001] = {0,};
    for (int i = 0; i < m; i++)
    {
        cin >> target[i];
        
        int result;
        // 정렬된 data 배열에서 target[i]가 있는지 0부터 n-1 범위 내에서 탐색
        result = binary_search(data, target[i], 0, n - 1);
        cout << result << "\n";
    }
    
    return 0;
}