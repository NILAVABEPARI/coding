#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size(), mProfit = INT_MIN, minVal = prices[0];
        for (int i = 1; i < n; i++)
        {
            mProfit = max(mProfit, prices[i] - minVal);
            minVal = min(minVal, prices[i]);
        }
        return mProfit;
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {7, 1, 5, 3, 6, 4};
    cout << "ans -- " << sol.maxProfit(nums);
}