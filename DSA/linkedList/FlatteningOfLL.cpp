#include <iostream>
#include <vector>
using namespace std;

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
private:
    ListNode *merge(ListNode *&head1, ListNode *&head2)
    {
        ListNode *dummy = new ListNode();
        ListNode *iter = dummy;
        while (head1 && head2)
        {
            if (head1->data < head2->data)
            {
                iter->child = head1;
                iter = head1;
                head1 = head1->child;
            }
            else
            {
                iter->child = head2;
                iter = head2;
                head2 = head2->child;
            }
            iter->next = NULL;
        }
        if (head1)
            iter->child = head1;
        if (head2)
            iter->child = head2;
        return dummy->child;
    }

public:
    ListNode *flattenLinkedList(ListNode *&head)
    {
        if (!head || !head->next)
            return head;
        ListNode *mergedHead = flattenLinkedList(head->next);
        head = merge(head, mergedHead);
        return head;
    }
};