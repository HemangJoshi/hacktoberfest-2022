// Problem Statement: Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that the tail’s next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

#include<bits/stdc++.h>
using namespace std;

class node {
    public:
        int num;
        node* next;
        node(int val) {
            num = val;
            next = NULL;
        }
};

void insertNode(node* &head,int val) {
    node* newNode = new node(val);
    if(head == NULL) {
        head = newNode;
        return;
    }
    node* temp = head;
    while(temp->next != NULL) temp = temp->next;
    
    temp->next = newNode;
    return;
}

void createCycle(node* &head,int pos) {
    node* ptr = head;
    node* temp = head;
    int cnt = 0;
    while(temp->next != NULL) {
        if(cnt != pos) {
            ++cnt;
            ptr = ptr->next;
        } 
        temp = temp->next;
    }
    temp->next = ptr;
}
//process as per mentioned in solution
node* detectCycle(node* head) {
    unordered_set<node*> st;
    while(head != NULL) {
        if(st.find(head) != st.end()) return head;
        st.insert(head);
        head = head->next;
    }
    return NULL;
}

int main() {
    node* head = NULL;
    
    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,3);
    insertNode(head,4);
    insertNode(head,3);
    insertNode(head,6);
    insertNode(head,10);
    
    createCycle(head,2);
    
    node* nodeRecieve = detectCycle(head);
    if(nodeRecieve == NULL) cout<<"No cycle";
    else {
        node* temp = head;
        int pos = 0;
        while(temp!=nodeRecieve) {
            ++pos;
            temp = temp->next;
        }
        cout<<"Tail connects at pos "<<pos<<endl;
    }
    
    return 0;
}
