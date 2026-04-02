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
    ListNode *sortList(ListNode *&head)
    {
        if (!head || !head->next)
            return head;
        ListNode *zHead = new ListNode(-1);
        ListNode *oHead = new ListNode(-1);
        ListNode *tHead = new ListNode(-1);
        ListNode *zero = zHead, *one = oHead, *two = tHead, *temp = head;
        while (temp)
        {
            if (temp->data == 0)
            {
                zero->next = temp;
                zero = zero->next;
            }
            else if (temp->data == 1)
            {
                one->next = temp;
                one = one->next;
            }
            else
            {
                two->next = temp;
                two = two->next;
            }
            temp = temp->next;
        }
        zero->next = oHead->next ? oHead->next : tHead->next;
        one->next = tHead->next;
        two->next = NULL;
        ListNode *newHead = zHead->next;
        delete *zHead;
        delete *oHead;
        delete *tHead;
        return newHead;
    }
};