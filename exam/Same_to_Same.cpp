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
bool are_lists_equal (Node * head, Node * head_2)
{
    
    Node *temp = head;
    Node *temp_2 = head_2;
    while (temp !=NULL && temp_2 !=NULL)
    {
        if (temp->val != temp_2->val)
        {
            return false;

        }
        temp = temp->next;
        temp_2 = temp_2 ->next;
    }
    return true;
    
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
int main()
{
    Node *head = take_input();
    Node * head_2 = take_input();
    if (are_lists_equal(head, head_2) && getCount(head) == getCount(head_2))
    {
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
    return 0;
}
