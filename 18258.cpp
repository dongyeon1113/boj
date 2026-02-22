#include <iostream>
#include <list>
#include <string>

using namespace std;

// std::list를 사용하여 큐의 기능을 추상화 (연결 리스트 기반)
list<int> q;

// 데이터 삽입: 리스트의 가장 뒤(back)에 추가
void push(int num)
{
    q.push_back(num);
}

// 데이터 추출: 리스트가 비어있지 않으면 가장 앞(front)의 값을 출력 후 제거
void pop()
{
    if(q.empty())
    {
        cout << "-1\n";
    }
    else
    {
        cout << q.front() << "\n";
        q.pop_front();
    }
}

// 현재 큐에 담긴 원소의 개수 출력
void size()
{
    cout << q.size() << "\n";
}

// 큐가 비어있는지 확인 (비었으면 1, 아니면 0)
void empty()
{
    if(q.empty())
    {
        cout << "1\n";
    }
    else
    {
        cout << "0\n";
    }
}

// 큐의 가장 앞에 있는 데이터 확인
void front()
{
    if(q.empty())
    {
        cout << "-1\n";
    }
    else
    {
        cout << q.front() << "\n";
    }
}

// 큐의 가장 뒤에 있는 데이터 확인
void back()
{
    if(q.empty())
    {
        cout << "-1\n";
    }
    else
    {
        cout << q.back() << "\n";
    }
}

int main()
{
    // 입출력 최적화: 대량의 명령 처리를 위해 필수적인 세팅
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string cmd;
        cin >> cmd;

        if(cmd == "push")
        {
            int num;
            cin >> num;
            push(num);
        }
        else if(cmd == "pop")
        {
            pop();
        }
        else if(cmd == "empty")
        {
            empty();
        }
        else if(cmd == "size")
        {
            size();
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
