#include <bits/stdc++.h>
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

void insertAtHead(node *&head, int val)
{
    node *toInsert = new node(val);

    if (head == nullptr)
    {
        toInsert->next = toInsert;
        head = toInsert;
        return;
    }

    toInsert->next = head;

    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = toInsert;
    head = toInsert;
}

void InsertAtTail(node *&head, int val)
{

    if (head == nullptr)
    {
        insertAtHead(head, val);
        return;
    }

    node *toInsert = new node(val);

    node *temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = toInsert;

    toInsert->next = head;
}

void display(node *head)
{
    node *temp = head;
    do
    {
        cout << temp->data << "->";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

void deleteAtHead(node *head)
{
    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    node *todelete = head;
    temp->next = head->next;
    head = head->next;
    delete todelete;
}

void deletion(node *head, int pos)
{
    if (pos == 1)
    {
        deleteAtHead(head);
        return;
    }
    node *temp = head;
    int count = 1;

    while (count != pos - 1)
    {
        temp = temp->next;
        count++;
    }
    node *todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}

int main()
{
    node *head = nullptr;
    InsertAtTail(head, 1);
    InsertAtTail(head, 2);
    InsertAtTail(head, 3);
    InsertAtTail(head, 4);
    InsertAtTail(head, 5);
    display(head);
    return 0;
}