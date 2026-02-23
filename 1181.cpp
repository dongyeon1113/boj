#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

// 정렬 기준: 1순위 길이, 2순위 사전순
bool compare(const string& a, const string& b) {
    if (a.length() != b.length()) {
        return a.length() < b.length(); // 길이 비교
    }
    return a < b; // 사전순 비교
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<string> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    // 1. 커스텀 정렬
    sort(vec.begin(), vec.end(), compare);

    // 2. 중복 제거 (정렬이 선행되어야 함)
    vec.erase(unique(vec.begin(), vec.end()), vec.end());

    // 3. 출력
    for (const string& s : vec) {
        cout << s << "\n";
    }

    return 0;
}