#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 정렬 기준 정의
bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    // 1순위: 종료 시간이 빠른 순서
    if (a.second != b.second) {
        return a.second < b.second;
    }
    // 2순위: 종료 시간이 같다면 시작 시간이 빠른 순서
    return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    // [Step 1] 그리디를 위한 정렬 수행
    sort(v.begin(), v.end(), compare);

    // [Step 2] 그리디 탐색 
    int cnt = 0;
    int last_end_time = 0; // 마지막 회의가 끝난 시간을 기록

    for (int i = 0; i < n; i++) {
        // 현재 회의의 시작 시간이 이전 회의 종료 시간 이후라면 선택 가능
        if (v[i].first >= last_end_time) {
            cnt++;
            last_end_time = v[i].second; // 종료 시간 갱신
        }
    }

    cout << cnt << "\n";

    return 0;
}