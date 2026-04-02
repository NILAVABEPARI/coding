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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = NULL;
        while (head)
        {
            ListNode *next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

public:
    bool isPalindrome(ListNode *head)
    {
        if (!head || !head->next)
            return true;
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = reverseList(slow->next);
        slow->next = NULL;
        slow = head;
        while (slow && fast)
        {
            if (slow->data != fast->data)
                return false;
            slow = slow->next;
            fast = fast->next;
        }
        return true;
    }
};