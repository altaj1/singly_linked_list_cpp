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
void print_linked_list(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}
int main()
{
    Node *head1 = take_input();
    Node *head2 = take_input();
    // print_linked_list(head1);
    
    int r1 = getCount(head1);
    int r2 = getCount(head2);
    if (r1 == r2)
    {
        cout<< "YES";
    }else{
        cout<< "NO";
    }
    
    // cout << r1 << " " << r2<< endl;
    return 0;
}

