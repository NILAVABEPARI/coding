#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size(), maxReach = 0, maxR = 0, jumps = 0;
        for (int i = 0; i < n - 1; i++)
        {
            maxR = max(maxR, i + nums[i]);
            if (maxReach == i)
            {
                jumps++;
                maxReach = maxR;
            }
        }
        return jumps;
    }
};

int main()
{
    vector<int> nums = {2, 3, 1, 1, 4};
    Solution sol;
    cout << "minimum jumps -- " << sol.jump(nums);
    return 0;
}