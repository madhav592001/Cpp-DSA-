#include <iostream>
#include <queue>
using namespace std;

// pop operation costly

class stack
{
    queue<int> q1;
    queue<int> q2;
    int N;

public:
    stack()
    {
        N = 0;
    }
    void pop()
    {
        if (!q1.empty())
        {
            return;
        }
        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        N--;
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }
    void push(int val)
    {
        q1.push(val);
        N++;
    }
    int top()
    {
        if (!q1.empty())
            return -1;

        while (q1.size() != 1)
        {
            q1.push(q1.front());
            q1.pop();
        }
        int ans = q1.front();
        q2.push(ans);

        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;

        return ans;
    }

    int size()
    {
        return N;
    }
};

int main()
{
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.pop();

    cout << st.size() << " ";
    cout << st.top() << " ";
    return 0;
}