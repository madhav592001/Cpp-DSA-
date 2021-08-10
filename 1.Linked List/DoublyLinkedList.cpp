#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int val)
    {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

void insertAtTail(node *&head, int val)
{
    node *toInsert = new node(val);

    node *temp = head;

    if (head == nullptr)
    {
        head = toInsert;
        return;
    }

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = toInsert;
    toInsert->prev = temp;
}

void insertAtHead(node *&head, int val)
{
    node *toInsert = new node(val);

    if (head != nullptr)
    {
        toInsert->next = head;
        head->prev = toInsert;
        head = toInsert;
    }
    else
    {
        head = toInsert;
    }
}

void display(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << " NULL ";
}

void deletion(node *head, int pos)
{
    if (pos == 1)
    {
        node *todelete = head;
        head = head->next;
        head->prev = nullptr;
        return;
    }
    node *temp = head;
    int count = 1;
    node *todelete;

    while (temp != nullptr && count != pos)
    {
        temp = temp->next;
        count++;
    }
    temp->prev->next = temp->next;
    if (temp->next != nullptr)
    {
        temp->next->prev = temp->prev;
    }
    delete temp;
}

void deleteAtHead(node *&head)
{
    node *todelete = head;
    head = head->next;
    head->prev = nullptr;

    delete todelete;
}

int length(node *head)
{
    int l = 0;
    node *temp = head;

    while (temp != nullptr)
    {
        l++;
        temp = temp->next;
    }
    return l;
}

node *appendK(node *&head, int k)
{
    int l = length(head);
    node *newHead;
    node *newTail;
    node *tail = head;
    int count = 1;

    while (tail->next != nullptr)
    {

        if (count == l - k)
        {
            newTail = tail;
        }
        if (count == l - k + 1)
        {
            newHead = tail;
        }
        tail = tail->next;
        count++;
    }
    newTail->next = nullptr;
    tail->next = head;
    return newHead;
}

void intersect(node *&head1, node *&head2, int pos)
{
    node *temp1 = head1;
    pos--;
    while (pos--)
    {
        temp1 = temp1->next;
    }
    node *temp2 = head2;
    while (temp2->next != nullptr)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp1;
}

int intersection(node *&head1, node *&head2)
{
    int l1 = length(head1);
    int l2 = length(head2);
    int d = 0;
    node *ptr1;
    node *ptr2;
    if (l1 > l2)
    {
        d = l1 - l2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else
    {
        d = l2 - l1;
        ptr1 = head2;
        ptr2 = head1;
    }
    while (d)
    {
        ptr1 = ptr1->next;
        if (ptr1 == nullptr)
            return -1;
        d--;
    }

    while (ptr1 != nullptr && ptr2 != nullptr)
    {
        if (ptr1 == ptr2)
        {
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return -1;
}



int main()
{
    node *head1 = nullptr;
    node *head2 = nullptr;
    insertAtTail(head1, 1);
    insertAtTail(head1, 4);
    insertAtTail(head1, 5);
    insertAtTail(head1, 7);
    insertAtTail(head2,2);
    insertAtTail(head2 , 3) ; 
    insertAtTail(head2 , 6) ;  


    // node* newHead = appendK(head,3) ;
    // display(newHead) ;

    return 0;
}