#include <iostream>
using namespace std;

// n번째 피보나치 수를 재귀적으로 구하는 함수
int fibonacci(int n)
{
    // 0번째 피보나치 수는 0
    if(n==0)
    {
        return 0;
    }
    // 1번째 피보나치 수는 1
    else if(n==1)
    {
        return 1;
    }

    // 점화식: F(n) = F(n-1) + F(n-2)
    return fibonacci(n-1)+fibonacci(n-2);
}

int main()
{
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    // 사용자로부터 n 입력
    cin>>n;

    // n번째 피보나치 수 출력
    cout<<fibonacci(n)<<"\n";
}