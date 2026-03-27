#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
private:
    int countStudents(vector<int> &nums, int pages)
    {
        int pagesStudent = 0, cnt = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] + pagesStudent <= pages)
                pagesStudent += nums[i];
            else
            {
                cnt++;
                pagesStudent = nums[i];
            }
        }
        return cnt;
    }

public:
    int findPages(vector<int> &nums, int m)
    {
        if (m > nums.size())
            return -1;
        int low = INT_MIN, high = 0;
        for (auto &it : nums)
        {
            low = max(low, it);
            high += it;
        }
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (countStudents(nums, mid) <= m)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {12, 34, 67, 90};
    int m = 2;
    cout << "maximum no. of paces -- " << sol.findPages(arr, m);
    return 0;
}