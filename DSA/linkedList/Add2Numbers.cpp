#include <iostream>
#include <vector>
#include <stack>
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        l1 = reverse(l1), l2 = reverse(l2);
        ListNode *ans = new ListNode(0);
        ListNode *tail = ans;
        int carry = 0;

        while (l1 || l2 || carry)
        {
            int currVal = carry;
            if (l1)
            {
                currVal += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                currVal += l2->val;
                l2 = l2->next;
            }
            tail->next = new ListNode(currVal % 10);
            tail = tail->next;
            carry = currVal / 10;
        }
        return reverse(ans->next);
    }

    // optimized -- without reversing the given lists
    ListNode *addTwoNumbers2(ListNode *l1, ListNode *l2)
    {
        stack<int> s1, s2;
        ListNode *ans = NULL;
        int carry = 0;
        while (l1)
        {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2)
        {
            s2.push(l2->val);
            l2 = l2->next;
        }

        while (!s1.empty() || !s2.empty() || carry)
        {
            int currVal = carry;
            if (!s1.empty())
            {
                currVal += s1.top();
                s1.pop();
            }
            if (!s2.empty())
            {
                currVal += s2.top();
                s2.pop();
            }
            ListNode *newNode = new ListNode(currVal % 10);
            newNode->next = ans;
            ans = newNode;
            carry = currVal / 10;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {9, 9, 9};
    vector<int> arr2 = {5, 6, 4};
    ListNode *head1 = new ListNode(arr[0]);
    ListNode *temp = head1;
    for (int i = 1; i < arr.size(); i++)
    {
        ListNode *curr = new ListNode(arr[i]);
        temp->next = curr;
        temp = curr;
    }
    ListNode *head2 = new ListNode(arr2[0]);
    temp = head2;
    for (int i = 1; i < arr2.size(); i++)
    {
        ListNode *curr = new ListNode(arr2[i]);
        temp->next = curr;
        temp = curr;
    }
    ListNode *newHead = sol.addTwoNumbers2(head1, head2);
    temp = newHead;
    while (temp)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    return 0;
}