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
        next = nullptr;
    }
};

node *lastToFront(node *head)
{

    node *temp = head;

    while (temp->next)
    {
        temp = temp->next;
    }
    node *newHead = temp;
    newHead->next = head;
    delete temp;
    return newHead;
}

void print(node *head)
{
    node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    node *head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);

    print(head);
    node *newHead = lastToFront(head);
    print(newHead);
    return 0;
}