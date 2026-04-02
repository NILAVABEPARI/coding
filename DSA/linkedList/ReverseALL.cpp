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
    ListNode *reverseList(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *prev = NULL;
        while (head)
        {
            ListNode *temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }
};