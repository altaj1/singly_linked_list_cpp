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
void min_max(Node *head)
{
    // int mn = INT_MAX;
    int mx = INT_MIN;


    Node *tmp = head;
    while (tmp != NULL)
    {
        // if(tmp->val < mn)
        // {
        //     mn = tmp->val;
        // }

        if(tmp->val > mx)
        {
            mx = tmp->val;
        }

        tmp = tmp->next;
    }
    cout << " " << mx << endl;
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
int main()
{
    Node * head = take_input();
    min_max(head);
    
    return 0;
}
