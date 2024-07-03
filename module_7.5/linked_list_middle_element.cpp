#include<bits/stdc++.h>
using namespace std;
class Node 
{
    public:
    int val;
    Node* next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};
void insert_tail(Node*& head, int val) {
    if (head == NULL) {
        head = new Node(val);
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new Node(val);
    }
}
int getCount(Node * head)
{
    int count = 0;
    Node * current = head;
    while (current!= NULL)
    {
        count ++;
        current = current->next;
    }
    return count;
}
Node* take_input ()
{
    Node* head = NULL;
    int val;
    while (true)
    {
        cin >> val;
        if (val == -1)
        {
            break;    
        }
        insert_tail( head, val);    
    }
     return head;
}

void middlePrint(Node * head, int count)
{
    // cout<< count;
    if(count%2==1)
    {
        int mid = count/2;
        // cout<< mid;
        Node* temp = head;
        for(int i=1;i<=mid;i++)
        {
            temp = temp->next;
        }
        cout << temp->val << endl;
    }else if (count % 2 == 0)
    {
        int mid = count/2;
        Node * temp = head;
        for (int i = 1; i < mid; i++)
        {
            temp = temp->next;
        }
        cout << temp->val << " " << temp->next->val <<endl;
    }
    
}
int main()
{
    Node *head = take_input();
    int count = getCount(head);
    middlePrint(head, count);
    return 0;
}
