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
void print_Recursion(Node *head)
{
    Node *tmp = head;

          if ( head == NULL)
          {
            return;
          }
          print_Recursion(head->next);
          cout << head->val << " ";
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
    Node *head = take_input();
    print_Recursion(head);
    return 0;
}
