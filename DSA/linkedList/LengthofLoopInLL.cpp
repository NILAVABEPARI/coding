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
    int findLengthOfLoop(ListNode *head)
    {
        ListNode *fast = head, *slow = head;
        bool isFound = false;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                isFound = true;
                break;
            }
        }
        int cnt = 1;
        if (isFound)
        {
            fast = fast->next;
            while (fast != slow)
            {
                fast = fast->next;
                cnt++;
            }
            return cnt;
        }
        return 0;
    }
};