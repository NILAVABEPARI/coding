#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int fast = nums[0], slow = nums[0];
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        fast = nums[0];
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {3, 1, 3, 4, 2};
    cout << "duplicate -- " << sol.findDuplicate(nums);
    return 0;
}