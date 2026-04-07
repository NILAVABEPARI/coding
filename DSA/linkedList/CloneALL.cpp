#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;
    ListNode *random;
    ListNode()
    {
        val = 0;
        next = NULL;
        random = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        random = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode *r)
    {
        val = data1;
        next = next1;
        random = r;
    }
};

class Solution
{
private:
    void *insertCopyInBetween(ListNode *head)
    {
        // connect all newly created nodes
        ListNode *temp = head;
        while (temp)
        {
            ListNode *newNode = new ListNode(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = temp->next->next;
        }
    }
    void connectRandomPointers(ListNode *head)
    {
        ListNode *temp = head;
        // connect the random pointers
        while (temp)
        {
            ListNode *copiedNode = temp->next;
            if (temp->random)
                copiedNode->random = temp->random->next;
            else
                copiedNode->random = NULL;
            temp = temp->next->next;
        }
    }
    ListNode *getDeepCopyList(ListNode *head)
    {
        ListNode *temp = head;
        ListNode *dummy = new ListNode(), *res = dummy;
        // disconnect the newly created nodes
        while (temp)
        {
            res->next = temp->next;
            res = res->next;
            temp->next = temp->next->next;
            temp = temp->next;
        }
        return dummy->next;
    }

public:
    ListNode *copyRandomList(ListNode *head)
    {
        if (!head)
            return NULL;
        // original node, copied node
        unordered_map<ListNode *, ListNode *> mp;
        ListNode *temp = head;
        while (temp)
        {
            ListNode *newNode = new ListNode(temp->val);
            mp[temp] = newNode;
            temp = temp->next;
        }
        // reassign temp to head
        temp = head;
        while (temp)
        {
            ListNode *copiedNode = mp[temp];
            copiedNode->next = mp[temp->next];
            copiedNode->random = mp[temp->random];
            temp = temp->next;
        }
        return mp[head];
    }
    ListNode *copyRandomList2(ListNode *head)
    {
        if (!head)
            return NULL;
        insertCopyInBetween(head);
        connectRandomPointers(head);
        return getDeepCopyList(head);
    }
};