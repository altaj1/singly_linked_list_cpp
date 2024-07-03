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
void sort(Node * head)
{
    
    Node * temp = head;
   
  while (temp != NULL)

  {
    Node * current = temp->next;
    while (current !=NULL)
    {
        if (temp->val < current->val)
        {
           swap(temp->val, current->val);
        }
        current = current->next;
    }
    temp = temp->next; 
  }
  

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
void print_link_list(Node *head)
{
     
     Node *tmp = head;
     while (tmp != NULL)
     {
        cout << tmp->val<< " ";
        tmp = tmp->next;
        
     }
     
}
int main()
{
    Node *head = take_input();
    sort(head);
    print_link_list(head);
    
    return 0;
}
