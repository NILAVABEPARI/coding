#include <iostream>
#include <vector>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int x)
    {
        val = x;
        next = NULL;
    }
};

class Solution
{
public:
    ListNode *reverse(ListNode *head)
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
    int pairSum(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = reverse(slow->next);
        slow = head;
        int maxi = INT_MIN;
        while (fast)
        {
            maxi = max(maxi, slow->val + fast->val);
            slow = slow->next;
            fast = fast->next;
        }
        return maxi;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {47, 22, 81, 46, 94, 95, 90, 22, 55, 91, 6, 83, 49, 65, 10, 32, 41, 26, 83, 99, 14, 85, 42, 99, 89, 69, 30, 92, 32, 74, 9, 81, 5, 9};
    ListNode *head = new ListNode(arr[0]);
    ListNode *temp = head;
    for (int i = 1; i < arr.size(); i++)
    {
        ListNode *curr = new ListNode(arr[i]);
        temp->next = curr;
        temp = curr;
    }
    cout << "max twin sum -- " << sol.pairSum(head);
    return 0;
}