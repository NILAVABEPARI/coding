#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> pq;
        for (auto &it : stones)
            pq.push(it);
        while (pq.size() > 1)
        {
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            if (first != second)
                pq.push(abs(first - second));
        }
        return pq.top();
    }
};

int main()
{
    vector<int> nums = {2, 7, 4, 1, 8, 1};
    Solution sol;
    cout << "last stone weight  -- " << sol.lastStoneWeight(nums);
    return 0;
}