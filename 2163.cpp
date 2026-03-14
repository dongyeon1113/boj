#include <iostream>
using namespace std;

int main()
{
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;

    // 가로와 세로 크기 입력
    cin>>n>>m;

    // 필요한 이동 횟수 출력
    // 가로로 (n-1)번, 세로로 (m-1)줄마다 n번씩 이동
    cout<<(n-1)+(m-1)*n;
}