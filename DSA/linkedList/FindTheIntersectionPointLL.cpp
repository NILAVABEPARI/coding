#include <iostream>
#include <vector>
using namespace std;

// Definition of singly linked list:
class ListNode
{
public:
    int data;
    ListNode *next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : data(x), next(next) {}
};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (!headA || !headB)
            return NULL;
        ListNode *slow = headA, *fast = headB;
        while (slow != fast)
        {
            slow = slow ? slow->next : headB;
            fast = fast ? fast->next : headA;
        }
        return slow;
    }
};