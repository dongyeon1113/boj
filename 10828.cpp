#include <iostream>
#include <string>

using namespace std;

/* * [BOJ 10828] 스택 직접 구현 (C++11 이상)
 * 학습 포인트: 배열을 이용한 LIFO(Last-In-First-Out) 자료구조의 원리
 */

// 전역 변수로 스택 메모리 영역과 스택 포인터(TOP) 구현
int st[10001] = {0,}; 
int TOP = -1; // 스택의 최상단 인덱스를 가리키는 포인터 (비어있을 때 -1)

// 데이터를 스택에 삽입: TOP을 먼저 증가시킨 후 해당 위치에 데이터 저장
void push(int num) {
    st[++TOP] = num;
}

// 데이터를 스택에서 추출: 가장 최근에 들어온 데이터를 출력하고 TOP을 감소
void pop() {
    if (TOP == -1) {
        cout << -1 << "\n";
    } else {
        cout << st[TOP] << "\n";
        st[TOP--] = 0; // 데이터 삭제 후 TOP 감소 
    }
}

// 스택의 현재 크기 반환: 인덱스는 0부터 시작하므로 TOP + 1이 현재 개수
void size() {
    cout << TOP + 1 << "\n";
}

// 스택이 비어있는지 확인: TOP이 초기값(-1)이면 비어있는 상태(1 반환)
void empty() {
    if (TOP == -1) cout << 1 << "\n";
    else cout << 0 << "\n";
}

// 스택의 최상단 데이터 확인: 추출(pop)하지 않고 값만 읽음
void top() {
    if (TOP == -1) cout << -1 << "\n";
    else cout << st[TOP] << "\n";
}

int main() {
    // 입출력 최적화: C standard stream과의 동기화를 끊어 실행 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string cmd;
        cin >> cmd;

        if (cmd == "push") {
            int num;
            cin >> num;
            push(num);
        } else if (cmd == "pop") {
            pop();
        } else if (cmd == "size") {
            size();
        } else if (cmd == "empty") {
            empty();
        } else if (cmd == "top") {
            top();
        }
    }
    return 0;
}