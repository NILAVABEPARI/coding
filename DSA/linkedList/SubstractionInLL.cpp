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
    // removing leading zeros
    ListNode *removeZeros(ListNode *head)
    {
        while (head && head->val == 0)
            head = head->next;
        return head ? head : new ListNode(0);
    }
    // returns true if 1st number >= 2nd number
    bool isGreaterOrEqual(ListNode *head1, ListNode *head2)
    {
        int len1 = 0, len2 = 0;
        ListNode *ptr1 = head1, *ptr2 = head2;
        while (ptr1)
        {
            ptr1 = ptr1->next;
            len1++;
        }
        while (ptr2)
        {
            ptr2 = ptr2->next;
            len2++;
        }
        if (len1 != len2)
            return len1 > len2;
        while (head1 && head2)
        {
            if (head1->val != head2->val)
                return head1->val > head2->val;
            head1 = head1->next;
            head2 = head2->next;
        }
        return true;
    }
    ListNode *subLinkedList(ListNode *head1, ListNode *head2)
    {
        head1 = removeZeros(head1);
        head2 = removeZeros(head2);

        if (!isGreaterOrEqual(head1, head2))
            swap(head1, head2);

        stack<int> s1, s2;
        while (head1)
        {
            s1.push(head1->val);
            head1 = head1->next;
        }
        while (head2)
        {
            s2.push(head2->val);
            head2 = head2->next;
        }

        ListNode *ans = NULL;
        int borrow = 0;

        while (!s1.empty())
        {
            int n = s1.top();
            s1.pop();
            int m = 0;
            if (!s2.empty())
            {
                m = s2.top();
                s2.pop();
            }

            n -= borrow;

            if (n < m)
            {
                n += 10;
                borrow = 1;
            }
            else
                borrow = 0;

            ListNode *node = new ListNode(n - m);
            node->next = ans;
            ans = node;
        }
        // Remove leading zeros (keep the last digit if it is zero)
        while (ans && ans->val == 0 && ans->next)
            ans = ans->next;
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> arr2 = {1, 0, 0, 0};
    vector<int> arr = {1};
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
    ListNode *newHead = sol.subLinkedList(head1, head2);
    temp = newHead;
    while (temp)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    return 0;
}