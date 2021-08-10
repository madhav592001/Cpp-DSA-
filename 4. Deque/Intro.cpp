#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<int> dq;
    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);
    dq.push_front(4);
    dq.push_front(5);
    dq.push_front(6);
    while (!dq.empty())
    {
        cout << dq.back() << " ";
        dq.pop_back();
    }
    return 0;
}