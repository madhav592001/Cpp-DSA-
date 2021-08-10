#include <iostream>
using namespace std;

class node
{

public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next == nullptr;
    }
};

class queue
{

    node *front;
    node *back;

public:
    queue()
    {
        front = nullptr;
        back = nullptr;
    }

    void push(int x)
    {
        node *toInsert = new node(x);

        if (front == nullptr)
        {
            back = toInsert;
            front = toInsert;
            return;
        }

        back->next = toInsert;
        back = toInsert;
    }

    void pop()
    {
        if (front == nullptr)
        {
            cout << "Queue is empty " << endl;
            return;
        }
        node *toDelete = front;
        front = front->next;
        delete toDelete;
    }

    int peek()
    {
        if (front == nullptr)
        {
            cout << "Queue is empty " << endl;
            return -1;
        }

        return front->data;
    }

    bool empty()
    {
        if (front == nullptr)
        {
            return true;
        }else{
        return false;
        }
    }
};

int main()
{
    queue q;
    q.push(4);
    q.push(6);
    q.push(5);

    cout << q.peek() << " ";
    q.pop();
    cout << q.peek() << " ";
    q.pop();
    cout << q.peek() << " ";
    q.pop();
    cout << q.empty();

    return 0;
}