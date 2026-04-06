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
private:
    ListNode *merge(ListNode *head1, ListNode *head2)
    {
        ListNode *dummy = new ListNode();
        ListNode *temp = dummy;
        while (head1 && head2)
        {
            if (head1->data < head2->data)
            {
                temp->next = head1;
                head1 = head1->next;
            }
            else
            {
                temp->next = head2;
                head2 = head2->next;
            }
            temp = temp->next;
        }
        if (head1)
            temp->next = head1;
        if (head2)
            temp->next = head2;
        return dummy->next;
    }
    ListNode *findMiddle(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

public:
    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *middle = findMiddle(head);
        ListNode *right = middle->next;
        middle->next = NULL;
        ListNode *left = head;

        left = sortList(left);
        right = sortList(right);
        return merge(left, right);
    }
};