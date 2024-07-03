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
void insert_at_tail(Node *&head, int v)
{
    Node * newNode = new Node(v);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *tmp = head;
    while ((tmp->next!= NULL))
    {
        tmp = tmp->next;
    }
     // tmp ekhon last node e
     tmp->next = newNode;
    
}
void print_link_list(Node *head)
{
     cout<< "Your Linked List:";
     Node *tmp = head;
     while (tmp != NULL)
     {
        cout << tmp->val<< " ";
        tmp = tmp->next;
        
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
bool duplicateValue(Node * head)
{
   bool flag = false;
   Node * temp = head;
   
  while (temp != NULL)

  {
    Node * current = temp->next;
    while (current !=NULL)
    {
        if (temp->val == current->val)
        {
           flag = true;
        }
        current = current->next;
    }
    temp = temp->next;
    
  }
  
   return flag;
}
bool sort(Node * head)
{
    bool flag = false;
    // Node * temp = head;

    for (Node * i = head; i->next!= NULL; i= i->next)
    {
       for (Node * j = i->next;  j!= NULL; j= j->next)
       {
        if (i->val > j->val)
        {
            flag = true;
            break;
        }
        
       }
       
    }
    
    // while (temp !=NULL)
    // {
    //    Node * current = temp->next;
    //    while (current !=NULL)
    //    {
    //     if (temp->val > current->val )
    //     {
    //         flag = true;
    //         break;
    //     }
    //     current = current->next;
    //    }
    //    temp = temp->next;
    // }
    return flag;
    
}
void middlePrint(Node * head, int count)
{
    // cout<< count;
    if(count%2==1)
    {
        int mid = count/2;
        cout<< mid;
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
void insertAnyPos(Node * &head, int pos, int valu)
{
    Node * newNode = new Node(valu);
    Node * temp = head;
    for (int i = 1; i < pos -1; i++)
    {
        temp = temp->next; 
    }
    newNode->next = temp->next;
    temp->next = newNode;
    
}
int main()
{
    Node *head = NULL;
    while (true)
    {
        cout<< endl;
        cout<< "Option 1: Insert at Tail" << endl;
        cout << "Opton 2: Print Linked List" << endl;
        cout << "Opton 3: Linked List size" << endl;
        cout << "Opton 4: Linked List any duplicate value" << endl;
        cout << "Opton 5: Linked List middlePrint" << endl;
        cout << "Opton 6: Linked List insert any pos" << endl;
        cout << "Opton 7: Linked List sort" << endl;
        int op;
        cin >> op;
        // cout<< op<< "this op";
        int count;
        if (op == 1)
        {
             cout << "Please enter value: " << endl;
              int v;
            while (1)
            {
              
            cin>> v;
            if (v == -1)
            {
                break;
            }
            
            insert_at_tail(head, v);
            }
            
           
            
        }else if (op == 2)
        {
            
            print_link_list(head);
        }
        else if (op == 3)
        {
            cout<< endl;
            count = getCount(head);
            cout << count<< " size of linklist" << endl ;
            
        }
        else if (op == 4)
        {
            cout<< endl;
            if (duplicateValue(head))
            {
                 cout << "YES" << endl ;
            }else{
                cout<< " NO" << endl;
            }   
        }
        // problem 3
        else if (op == 5)
        {
            count = getCount(head);
             middlePrint(head , count);
        }
        // problem 4
        else if (op == 6)
        {
            cout<< " enter pos & value"<< endl;
            int pos, valu;
            cin>> pos >> valu;
            if (!pos || !valu)
            {
                cout << "Invalid" << endl;
               break;
            }
            
            // cout << pos << " "<< valu << endl;
            insertAnyPos(head, pos, valu);
        }else if (op == 7)
        {
            if (sort(head))
            {
                cout << "No"<< endl;
            }else{
                
                cout<< " Yes"<< endl;
            }
            
        }
        
        
        
      
    }
    
    return 0;
}
