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
    int lengthOfLL(ListNode *head)
    {
        int length = 0;
        while (head)
        {
            head = head->next;
            length++;
        }
        return length;
    }
    ListNode *kthNode(ListNode *head, int k)
    {
        for (int i = 1; i < k; i++)
            head = head->next;
        return head;
    }
    ListNode *swapNodes(ListNode *head, int k)
    {
        int length = lengthOfLL(head);
        ListNode *kthFromStart = kthNode(head, k), *kthFromEnd = kthNode(head, length - k + 1);
        swap(kthFromEnd->val, kthFromStart->val);
        return head;
    }

    ListNode *swapNodes2(ListNode *head, int k)
    {
        ListNode *temp = head, *kthFromStart = NULL, *kthFromEnd = head;
        k--;
        while (k--)
            temp = temp->next;
        kthFromStart = temp;
        while (temp->next)
        {
            temp = temp->next;
            kthFromEnd = kthFromEnd->next;
        }
        swap(kthFromEnd->val, kthFromStart->val);
        return head;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {7, 9, 6, 6, 7, 8, 3, 0, 9, 5};
    ListNode *head = new ListNode(arr[0]);
    ListNode *temp = head;
    for (int i = 1; i < arr.size(); i++)
    {
        ListNode *curr = new ListNode(arr[i]);
        temp->next = curr;
        temp = curr;
    }
    ListNode *newHead = sol.swapNodes2(head, 5);
    temp = newHead;
    while (temp)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    return 0;
}