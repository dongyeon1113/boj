#include <iostream>
#include <algorithm>
using namespace std;

/**
 * 백준 13305: 주유소
 * 알고리즘: 그리디(Greedy)
 * 핵심: 다음 도시로 갈 때, 지금까지 지나온 주유소 중 가장 저렴한 곳의 가격을 선택한다.
 */

int main()
{
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    // 도시 사이의 거리는 최대 10억, 주유소 가격도 최대 10억이므로 
    // 결과값과 배열 요소 모두 long long 타입을 사용하는 것이 안전함
    long long length[100001] = {0,};
    long long gas_station[100001] = {0,};

    // 1. 도로의 길이 입력
    for(int i = 0; i < n - 1; i++)
    {
        cin >> length[i];
    }
    
    // 2. 주유소 리터당 가격 입력
    for(int i = 0; i < n; i++)
    {
        cin >> gas_station[i];
    }

    long long min_cost = 0; // 총 최소 비용
    
    /**
     * 그리디 탐색 수행
     * i번째 도시에서 i+1번째 도시로 갈 때의 비용을 계산
     */
    for(int i = 0; i < n - 1; i++)
    {
        // 현재 방문한 도시의 주유소 가격이 다음 도시보다 비싸다면?
        if(gas_station[i] > gas_station[i + 1])
        {
            // 현재 가격으로 이번 구간을 결제
            min_cost += gas_station[i] * length[i];
        }
        else
        {
            // 현재 가격이 다음 도시보다 싸다면, 다음 도시에서도 현재 가격을 적용함
            // (즉, 미리 싼 곳에서 다음 구간까지 주유한다는 개념)
            min_cost += gas_station[i] * length[i];
            swap(gas_station[i], gas_station[i + 1]); 
        }
    }

    cout << min_cost << endl;

    return 0;
}