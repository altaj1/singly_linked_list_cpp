#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

void insert_at_head(Node*& head, Node*& tail, int v) {
    Node* newNode = new Node(v);
    newNode->next = head;
    head = newNode;
    if (tail == NULL) {
        tail = head;
    }
}

void insert_tail(Node*& head, Node*& tail, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

void print_link_list(Node* head) {
    Node* tmp = head;
    while (tmp != NULL) {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
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

void delete_head(Node*& head, Node*& tail) {
    if (head == NULL) return;
    Node* deleteNode = head;
    head = head->next;
    if (head == NULL) {
        tail = NULL;
    }
    delete deleteNode;
}

void delete_from_position(Node*& head, Node*& tail, int v) {
    if (head == NULL)
    {
        return;
    }
    
    if (v == 0) {
        delete_head(head, tail);
        return;
    }
    int size = getCount(head);
    // cout << size<< endl;
    // if (size > v)
    // {
    //    return;
    // }
    
    Node* tmp = head;
    for (int i = 0; i < v - 1; ++i) {
        if (tmp == NULL || tmp->next == NULL) return; 
        tmp = tmp->next;
    }

    if (tmp->next == NULL) return;

    Node* deleteNode = tmp->next;
    tmp->next = tmp->next->next;
    if (tmp->next == NULL) {
        tail = tmp;
    }
    delete deleteNode;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int x, v;
        cin >> x >> v;
        if (x == 0) {
            insert_at_head(head, tail, v);
        } else if (x == 1) {
            insert_tail(head, tail, v);
        } else if (x == 2) {
        //     if (getCount(head) < v)
        //     {
        //         return 0;
        //     }
        //    else 
           delete_from_position(head, tail, v);
        }
        
        print_link_list(head);
        // cout << getCount(head);
    }
    // int size = getCount(head);
    // cout << size;
    return 0;
}
