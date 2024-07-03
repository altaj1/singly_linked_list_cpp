#include<bits/stdc++.h>
using namespace std;
class Node 
{
    public:
    int val;
    Node * next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};
void insert( Node *&head, int v)
{
    Node * newNode = new Node(v);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp= temp->next;
    }
    temp->next = newNode;

    
}
int main()
{
    Node *head = NULL;
    int v;
    while (1)
    {
        cin>> v;
        if (v == -1)
        {
            break;
        }
        insert(head, v);
    }
    
    return 0;
}
