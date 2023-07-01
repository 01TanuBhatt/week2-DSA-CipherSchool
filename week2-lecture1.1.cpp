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
    Node(int val) : val(val), next(nullptr) {}
};

Node * copy (Node * head) {
    unordered_map<Node*,Node*>hash;
    Node * ptr = head;
    while(ptr != NULL)
    {
        Node * copiedNode = new Node(ptr->val);
        hash[ptr] = copiedNode;
        ptr = ptr->next;
    }
    ptr=head;
    while(ptr != NULL)
    {
       
        Node * copied = hash[ptr];
        copied->next = hash[ptr->next];
        copied->random = hash[ptr->random];
        ptr = ptr->next;
    }
    return hash[head];
}
int main()
{

}