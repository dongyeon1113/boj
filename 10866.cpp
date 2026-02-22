#include <iostream>
#include <string>
#include <deque>

using namespace std;

// 전역 덱 선언: 앞뒤 양방향에서 삽입/삭제 가능
deque<int> dq;

// 덱의 뒤쪽에 데이터 삽입
void push_back(int num)
{
    dq.push_back(num);
}

// 덱의 앞쪽에 데이터 삽입
void push_front(int num)
{
    dq.push_front(num);
}

// 덱의 앞쪽 데이터를 출력하고 삭제 (비어있으면 -1)
void pop_front()
{
    if(dq.empty())
    {
        cout << -1 << "\n";
    }
    else {
        cout << dq.front() << "\n";
        dq.pop_front();    
    }
}

// 덱의 뒤쪽 데이터를 출력하고 삭제 (비어있으면 -1)
void pop_back()
{
    if(dq.empty())
    {
        cout << -1 << "\n";
    }
    else {
        cout << dq.back() << "\n";
        dq.pop_back();    
    }
}

// 현재 덱에 저장된 원소의 개수 출력
void size()
{
    cout << dq.size() << "\n";
}

// 덱이 비어있는지 확인 (비었으면 1, 아니면 0)
void empty()
{
    if(dq.empty())
    {
        cout << 1 << "\n";
    }
    else {
        cout << 0 << "\n";
    }
}

// 덱의 가장 앞에 있는 원소 확인
void front()
{
    if(dq.empty())
    {
        cout << -1 << "\n";
    }
    else {
        cout << dq.front() << "\n"; 
    }
}

// 덱의 가장 뒤에 있는 원소 확인
void back()
{
    if(dq.empty())
    {
        cout << -1 << "\n";
    }
    else {
        cout << dq.back() << "\n";
    }
}

int main() {
    // I/O 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n; 

    for (int i = 0; i < n; i++)
    {
        string cmd;
        cin >> cmd;

        if(cmd == "push_back")
        {
            int num;
            cin >> num;
            push_back(num);
        }
        else if(cmd == "push_front")
        {
            int num;
            cin >> num;
            push_front(num);
        }
        else if(cmd == "pop_front")
        {
            pop_front();
        }
        else if(cmd == "pop_back")
        {
            pop_back();
        }
        else if(cmd == "size")
        {
            size();
        }
        else if(cmd == "empty")
        {
            empty();
        }
        else if(cmd == "front")
        {
            front();
        }
        else if(cmd == "back")
        {
            back();
        }
    }
    return 0;
}