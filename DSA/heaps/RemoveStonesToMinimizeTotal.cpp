#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int minStoneSum(vector<int> &piles, int k)
    {
        int total = 0;
        priority_queue<int> pq;
        for (auto &it : piles)
            pq.push(it);
        while (k--)
        {
            int top = pq.top();
            pq.pop();
            pq.push((top - (top / 2)));
        }
        while (!pq.empty())
        {
            total += pq.top();
            pq.pop();
        }
        return total;
    }
};

int main()
{
    vector<int> nums = {5, 4, 9};
    int k = 2;
    Solution sol;
    cout << "minimum total  -- " << sol.minStoneSum(nums, k);
    return 0;
}