#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int main()
{ 
    // 입출력 속도 향상 (시간 초과 방지)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    stack<int> s;
    vector<string> str_vec; // 연산 결과(+, -) 저장용 벡터
    int n;
    cin >> n;

    int cnt = 1;      // 스택에 넣을 오름차순 숫자 (1부터 시작)
    bool flag = true; // 수열 가능 여부 확인용 플래그

    for (int i = 0; i < n; i++)
    {
        int target;
        cin >> target;

        // target 숫자가 나올 때까지 숫자를 push하고 '+' 기록
        while (cnt <= target)
        {
            s.push(cnt);
            str_vec.push_back("+");
            cnt++;
        }

        // 스택의 top이 현재 찾아야 하는 target과 같다면 pop하고 '-' 기록
        if (target == s.top())
        {
            s.pop();
            str_vec.push_back("-");
        }
        // 스택의 top과 target이 맞지 않으면 수열 생성 불가능
        else {
            flag = false;
        }
    }

    // 결과 출력
    if (!flag)
    {
        cout << "NO\n"; // 실패 시 NO 출력
        return 0;
    }
    else
    {
        // 성공 시 저장해둔 연산 기록 전체 출력
        for (int i = 0; i < str_vec.size(); i++)
        {
            cout << str_vec[i] << "\n";
        }
    }

    return 0;
}
