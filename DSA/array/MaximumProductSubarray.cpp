#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // brute force --
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size(), maxi = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int prod = 1;
            for (int j = i; j < n; j++)
            {
                prod *= nums[j];
                maxi = max(maxi, prod);
            }
        }
        return maxi;
    }

    // optimal --
    int maxProduct2(vector<int> &nums)
    {
    }
};

int main()
{
    vector<int> arr = {1, -2, 3, 4, -4, -3};
    Solution sol;
    int ans = sol.maxProduct2(arr);
    cout << "max product subarray -- " << ans;
    return 0;
}