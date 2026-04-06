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
    ListNode *reverse(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *prev = NULL, *temp = head;
        while (temp)
        {
            ListNode *nextNode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextNode;
        }
        return prev;
    }
    ListNode *findKthNode(ListNode *head, int k)
    {
        ListNode *temp = head;
        k--;
        while (temp && k)
        {
            k--;
            temp = temp->next;
        }
        return temp;
    }

public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (!head || !head->next)
            return head;
        ListNode *temp = head, *prevlast = NULL;
        while (temp)
        {
            ListNode *kthNode = findKthNode(temp, k);
            if (kthNode == NULL)
            {
                if (prevlast)
                    prevlast->next = temp;
                break;
            }
            // store the next node after the kth node
            ListNode *nextNode = kthNode->next;
            // disconnect the kth node to prepare for reversal
            kthNode->next = NULL;
            // reverse the nodes from temp ot the kth node
            reverse(temp);
            // adjust head of the reversal starts from head
            if (temp == head)
                head = kthNode;
            else
                prevlast->next = kthNode;

            prevlast = temp;
            temp = nextNode;
        }
        return head;
    }
};