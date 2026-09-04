#include <iostream>
#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    ListNode()
    {
        val = 0;
        ListNode = NULL;
    }
    ListNode(int x)
    {
        val = x;
        ListNode = NULL;
    }
};

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !head->next || k == 0)
            return head;
        int cnt = 0;
        ListNode *curr = head, prev = NULL;
        while (curr)
        {
            curr = curr->next;
            cnt++;
        }
        k = k % cnt;
        if (k == 0)
            return head;
        curr = head;
        for (int i = 1; i <= cnt - k; i++)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = NULL;
        ListNode *newHead = curr;
        while (curr)
            curr = curr->next;
        curr->next = head;
        return newHead;
    }
};

int main()
{
    Solution sol;
    ListNode *head = new ListNode(1);
    head = sol.rotateRight(head, 2);
    return 0;
}