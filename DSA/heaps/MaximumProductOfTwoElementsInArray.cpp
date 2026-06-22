#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        // using simple sorting --
        // sort(nums.begin(), nums.end());
        // int n = nums.size();
        // return ((nums[n-1]-1) * (nums[n-2]-1));

        // using 2 variables --
        int n = nums.size(), max1 = INT_MIN, max2 = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > max1)
            {
                max2 = max1;
                max1 = nums[i];
            }
            else if (nums[i] > max2)
                max2 = nums[i];
        }
        return ((max1 - 1) * (max2 - 1));
    }
};

int main()
{
    return 0;
}