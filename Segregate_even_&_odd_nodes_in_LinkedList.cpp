// Problem Statement : Segregate even and odd nodes in LinkedList

// Given a LinkedList of integers. Modify the LinkedList in such a way that in Modified LinkedList all the even numbers appear before all the odd numbers in LinkedList.

// Also, note that the order of even and odd numbers should remain the same. 

// Examples:

// Example 1:
// Input: 1→2→3→4→5→6→Null
// Output: 2→4→6→1→3→5→Null
// Explanation : 
// Odd Nodes in LinkedList are 1,3,5 and 
// Even Nodes in LinkedList are 2,4,6
// In Modified LinkedList all even Nodes comes before 
// all Odd Nodes. So Modified LinkedList looks like 
// 2→4→6→1→3→5→Null. Order of even and odd Nodes is 
// maintained in modified LinkedList.

// Example 2:
// Input: 1→3→5→Null
// Output: 1→3→5→Null
// Explantion: As there are no Even Nodes in LinkedList, 
// The Modified LinkedList is same as Original LinkedList.

// Example 3:
// Input: 2→4→6→8→Null
// Output: 2→4→6→8→Null
// Explanation: As there are no Odd Nodes in LinkedList, 
// The Modified LinkedList is same as Original LinkedList.

#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int x)
    {
        val = x;
        next = nullptr;
    }
};

ListNode *head, *tail; // head and tail of the LinkedList

void PrintList(ListNode *head) // Function to print the LinkedList
{
    ListNode *curr = head;
    for (; curr != nullptr; curr = curr->next)
        cout << curr->val << "-->";
    cout << "null" << endl;
}

void InsertatLast(int value) // Function for creating a LinkedList
{

    ListNode *newnode = new ListNode(value);
    if (head == nullptr)
        head = newnode, tail = newnode;
    else
        tail = tail->next = newnode;
}

ListNode *SegregatetoOddEVen()
{
    // creating Heads of Odd and Even LinkedLists
    ListNode *oddHead = new ListNode(-1), *oddTail = oddHead;
    ListNode *evenHead = new ListNode(-1), *evenTail = evenHead;
    ListNode *curr = head, *temp;
    while (curr)
    {
        // Breaking the Link of the curr Node.
        temp = curr;
        curr = curr->next;
        temp->next = nullptr;

        if (temp->val & 1) // If odd Node,append to odd LinkedList
        {
            oddTail->next = temp;
            oddTail = temp;
        }
        else // If Even Node,append to even LinkedList
        {
            evenTail->next = temp;
            evenTail = temp;
        }
    }
    evenTail->next = oddHead->next; 
    // Appending Odd LinkedList at end of EvenLinkedList
    return evenHead->next;
} 

int main()
{
    InsertatLast(1);
    InsertatLast(2);
    InsertatLast(3);
    InsertatLast(4);
    cout << "Initial LinkedList : " << endl;
    PrintList(head);
    ListNode *newHead = SegregatetoOddEVen();
    cout << "LinkedList After Segregration " << endl;
    PrintList(newHead);
    return 0;
}
