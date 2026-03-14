#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 매우 큰 수 두 개를 문자열로 받아 덧셈한 결과를 반환하는 함수
string addbig(string a,string b)
{
    string res="";
    
    // 뒤에서부터 계산하기 쉽도록 문자열을 뒤집음
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());

    int carry=0;

    // a의 각 자리를 순회하며 b의 같은 자리와 더함
    for(int i=0; i<a.size(); i++)
    {
        // a의 현재 자리 숫자
        int x=a[i]-'0';
        int y;

        // b의 길이를 넘어가면 해당 자리는 0으로 처리
        if(i>=b.size())
        {
            y=0;
        }
        else{
            // b의 현재 자리 숫자
            y=b[i]-'0';
        }

        // 현재 자리 합 + 올림값
        int sum=x+y+carry;

        //cout<<sum<<"\n";

        // 현재 자리 결과를 문자열에 추가
        res+=char(sum%10+'0');

        // 다음 자리로 넘길 올림값 계산
        carry=sum/10;
    }

    // 마지막 올림값이 남아 있으면 결과에 추가
    if(carry!=0)
    {
        res+=char(carry+'0');
    }

    // 뒤집힌 결과를 다시 원래 순서로 복구
    reverse(res.begin(),res.end());
    return res;
}

int main()
{
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    // 큰 피보나치 수를 저장하기 위해 문자열 배열 사용
    string fibonacci[10001]={"",};

    // 초기 피보나치 값 설정
    fibonacci[0]="0";
    fibonacci[1]="1";

    // 점화식을 이용해 2번째부터 n번째까지 계산
    for(int i=2; i<=n; i++)
    {
        fibonacci[i]=addbig(fibonacci[i-1],fibonacci[i-2]);
    }

    // n번째 피보나치 수 출력
    cout<<fibonacci[n]<<"\n";   
}