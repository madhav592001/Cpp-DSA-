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
        next = NULL;
    }
};

void insertAtTail(node *&head, int val)
{
    node *n = new node(val);

    if (head == NULL)
    {
        head = n;
        return;
    }

    node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << " NULL ";
}

bool search(node *head, int key)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void deleteAtHead(node *&head)
{
    node *todelete = head;
    head = head->next;
    delete todelete;
}

void deletion(node *&head, int val)
{
    if (head == NULL)
    {
        return;
    }
    if (head->next == NULL)
    {
        deleteAtHead(head);
    }
    node *temp = head;

    while (temp->next->data != val)
    {
        temp = temp->next;
    }
    node *todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}

node *reverse(node *&head)
{ // iterator way
    node *prevptr = nullptr;
    node *currptr = head;
    node *nextptr;

    while (currptr != nullptr)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nextptr;
    }
    return prevptr; // new head
}

node *reverseRecursive(node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    node *newHead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = nullptr;

    return newHead;
}

node *reverseK(node *&head, int k)
{
    node *prevptr = nullptr;
    node *currptr = head;
    node *nextptr;
    int count = 0;

    while (currptr != nullptr && count < k)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nextptr;
        count++;
    }
    if (nextptr != nullptr)
    {
        head->next = reverseK(nextptr, k); // loop khatm hone par next pointer aage wale pe pointed hoga kyuki current pointer last
    }                                      // hoga loop ma

    return prevptr;
}

void makeCycle(node *&head, int pos)
{
    node *temp = head;
    node *startNode;

    int count = 1;

    while (temp->next != nullptr)
    {
        if (count == pos)
        {
            startNode = temp; // start node vo hoga jaha se cycle banani ha
        }
        temp = temp->next;
        count++;
    }
    temp->next = startNode; // temp last node tak chalega to uske next hum start node pe point kar..
}

bool detectCycle(node *&head)
{
    node *slow = head; // tortoise
    node *fast = head; // hare
    while (fast != nullptr && fast->next != nullptr)
    { // agar cyclic nhi ha to fast hamesha aage rahega
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}

void removeCycle(node *&head)
{
    node *slow = head;
    node *fast = head;
    node *temp = head;

    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);

    fast = head;

    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = nullptr;
}

node* merge(node* head1 , node* head2 ){
    node* p1 = head1 ; 
    node* p2 = head2 ; 

    node* dummyNode = new node(-1) ; 
    node* p3 = dummyNode; 

    while(p1!=nullptr && p2!=nullptr){
        if(p1->data < p2->data ){
            p3->next = p1 ; 
            p1 = p1->next ; 
        }
        else{
            p3->next = p2 ;
            p2=p2->next ; 
        }
        p3=p3->next ; 
    }

    while(p1 !=nullptr){
        p3->next = p1 ; 
        p1=p1->next ; 
        p3=p3->next ;
    }

      while(p2 !=nullptr){
        p3->next = p2 ; 
        p2=p2->next ; 
        p3=p3->next ;
    }

    return dummyNode->next ;
    
}

// put even elements after odd elements in linked list

void evenafterodd(node* head){
    node* odd = head ;
    node* even= head->next ; 
    node* evenStart = head->next ; 

    while(odd->next != nullptr && even->next !=nullptr ){
        odd->next = even->next ; 
        odd=odd->next ;
        even->next = odd->next ; 
        even=even->next ; 

    }
    odd->next = evenStart ; 
    if(odd->next == nullptr){
        even->next = nullptr ; 
    }
}

int main()
{
    node* head = nullptr ; 
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);

    evenafterodd(head) ; 

    display(head) ; 

//      node *head1 = nullptr;
//     node *head2 = nullptr;
//     insertAtTail(head, 1);
//     insertAtTail(head1, 4);
//     insertAtTail(head1, 5);
//     insertAtTail(head1, 7);
//     insertAtTail(head2,2);
//     insertAtTail(head2 , 3) ; 
//     insertAtTail(head2 , 6) ;  

//    display(merge(head1,head2)) ; 


    // node *head = NULL;

    // insertAtTail(head, 1);
    // insertAtTail(head, 2);
    // insertAtTail(head, 3);
    // insertAtTail(head, 4);
    // insertAtTail(head, 5);
    // insertAtTail(head, 6);

    // makeCycle(head, 3);
    // cout << detectCycle(head) << endl;
    // removeCycle(head);
    // display(head);
    // cout << detectCycle(head) << endl;

    // display(head) ;

    // deletion(head, 2);
    // display(head);

    // node *newHead = reverse(head);

    // display(newHead);

    return 0;
}