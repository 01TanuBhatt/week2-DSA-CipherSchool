#include <bits/stdc++.h>
using namespace std;
class ListNode
{
    public:
    int val;
    ListNode *next;
    ListNode() : val(0),next(nullptr){}
    ListNode(int x) : val(x),next(nullptr) {}
    ListNode(int x,ListNode *next) : val(x),next(next) {}
};

class Node{
    public:
    int val;
    Node *next, *random;
};

class Node{
    public:
    int val;
    Node *next, *random;
    Node(int val) : val(val), next(nullptr) {}
};

Node * copy(Node * head)
{
    if(head == NULL)
    {
        return NULL;
    }
    Node * ptr = head, *qtr=NULL;
    while(ptr != NULL)
    {
        qtr = ptr->next;
        Node * newNode = new Node(ptr->val);
        newNode->next = qtr;
        ptr->next = newNode;
        ptr=ptr->next;
    }
}
int main()
{

}