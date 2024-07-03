#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
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
        insert_tail( head, val );    
    }
     return head;
}
void delete_val(Node *&head, int x)
{
    // if(head->val == x)
    // {
    //     Node* deletenode = head;
    //     head = head->next;
    //     delete deletenode;
    //     return;
    // }

    Node *tmp = head;
    while (tmp->next != NULL)
    {
        if(tmp->next->val == x)
        {
            Node* deletenode = tmp->next;
            tmp->next = tmp->next->next;
            delete deletenode;
            // break;
        }
        tmp = tmp->next;
    }
}
void remove_duplicate(Node * &head)
{
    // if (!head)
    // {
    //     return;
    // }
    
    Node * temp = head;
     while (temp !=NULL)
    {
       Node * current = temp->next;
       while (current !=NULL)
       {
        if (temp->val == current->val )
        { 
            delete_val(head, current->val );
            //  Node* deleteNode = current;
            //  temp->next = current->next;
            //  delete deleteNode;
        }
        current = current->next;
       }
       temp = temp->next;
    }
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
    Node * head = take_input();
    remove_duplicate(head);
    print_link_list(head);
    
    return 0;
}
