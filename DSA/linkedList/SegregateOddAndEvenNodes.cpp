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
    ListNode *oddEvenList(ListNode *&head)
    {
        if (!head || !head->next)
            return head;
        ListNode *even = head->next, *odd = head, *firstEven = head->next;
        while (even && even->next)
        {
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = firstEven;
        return head;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {1, 2, 3, 4, 5};
    return 0;
}