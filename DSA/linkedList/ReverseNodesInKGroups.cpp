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
        return head;
    }
    ListNode *findKthNode(ListNode *head, int k)
    {
        k--;
        while (head && k--)
            head = head->next;
        return head;
    }
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (!head)
            return head;
        ListNode *tempHead = head, *prevLast = NULL;
        while (tempHead)
        {
            ListNode *kthNode = findKthNode(tempHead, k);
            if (!kthNode)
            {
                if (prevLast)
                    prevLast->next = tempHead;
                break;
            }
            ListNode *nextNode = kthNode->next;
            kthNode->next = NULL;
            reverse(tempHead);
            if (tempHead == head)
                head = kthNode;
            else
                prevLast->next = kthNode;
            prevLast = tempHead;
            tempHead = nextNode;
        }
        return head;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 2;
    ListNode *head = new ListNode(arr[0]);
    ListNode *temp = head;
    for (int i = 1; i < arr.size(); i++)
    {
        ListNode *curr = new ListNode(arr[i]);
        temp->next = curr;
        temp = curr;
    }
    ListNode *newHead = sol.reverseKGroup(head, k);
    temp = newHead;
    while (temp)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    return 0;
}