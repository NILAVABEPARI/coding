#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<pair<int, ListNode *>, vector<pair<int, ListNode *>>, greater<pair<int, ListNode *>>> pq;
        for (auto &it : lists)
        {
            if (it)
                pq.push({it->val, it});
        }
        ListNode *head = NULL, *nextptr = NULL;
        while (!pq.empty())
        {
            auto temp = pq.top();
            pq.pop();
            if (temp.second->next)
                pq.push({temp.second->next->val, temp.second->next});
            if (!head)
            {
                head = temp.second;
                nextptr = head;
            }
            else
            {
                nextptr->next = temp.second;
                nextptr = nextptr->next;
            }
        }
        if (nextptr)
            nextptr->next = NULL;
        return head;
    }
};

vector<ListNode *> createLists(vector<vector<int>> &nums)
{
    vector<ListNode *> lists;
    for (auto &vec : nums)
    {
        ListNode *head = nullptr;
        ListNode *tail = nullptr;
        for (int x : vec)
        {
            ListNode *node = new ListNode(x);
            if (!head)
                head = tail = node;
            else
            {
                tail->next = node;
                tail = node;
            }
        }
        lists.push_back(head);
    }
    return lists;
}

int main()
{
    vector<vector<int>> nums = {{1, 4, 5}, {1, 3, 4}, {2, 6}};
    vector<ListNode *> arr = createLists(nums);
    Solution sol;
    ListNode *head = sol.mergeKLists(arr);
    cout << "merged list -- " << endl;
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}