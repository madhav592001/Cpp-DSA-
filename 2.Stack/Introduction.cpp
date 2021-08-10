#include <iostream>
using namespace std;

#define n 100

class stack
{

    int *arr;
    int top;

public:
    stack()
    {
        arr = new int[n];
        top = -1;
    }

    void push(int x)
    {

        if (top == n - 1)
        {
            cout << "stack overflow " << endl;
        }
        top++;
        arr[top] = x;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "no element to pop " << endl;
        }
        top--;
    }

    int Top()
    {
        if (top == -1)
        {
            cout << "no element in Stack " << endl;
            return -1;
        }
        return arr[top];
    }

    bool empty()
    {
        return top == -1;
    }
};



int main()
{

    stack s;
    s.push(1);
    s.push(14);
    s.push(12);
    s.push(12);

    cout << s.empty() << endl;

    return 0;
}