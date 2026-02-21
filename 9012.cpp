#include <iostream>
#include <string>

using namespace std;

// 전역 변수로 스택 포인터 관리
int TOP = -1; 

// 스택 삽입: 인덱스 증가 후 데이터 저장
void push(char st[], char data) {
    st[++TOP] = data;
}

// 스택 추출: 인덱스 감소 (논리적 삭제)
void pop(char st[]) {
    st[TOP--] = 0; 
}

int main() {
    // I/O 성능 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    while (n--) {
        string cmd;
        cin >> cmd;
        
        char st[51] = {0,}; 
        TOP = -1; // 각 테스트 케이스마다 스택 포인터 초기화

        for (int j = 0; j < cmd.length(); j++) {
            // 1. 여는 괄호는 무조건 스택에 삽입
            if (cmd[j] == '(') {
                push(st, cmd[j]);
            } 
            // 2. 닫는 괄호일 때 스택 상단에 여는 괄호가 있으면 짝이 맞으므로 제거
            else if (cmd[j] == ')' && TOP != -1 && st[TOP] == '(') {
                pop(st);
            } 
            // 3. 그 외 (비어있는 스택에 닫는 괄호 등)는 스택에 쌓아 결과적으로 NO가 나오게 유도
            else {
                push(st, cmd[j]);
            }
        }

        // 최종 판단: 스택이 완전히 비어 있어야 유효한 괄호 쌍(VPS)
        if (TOP == -1) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}