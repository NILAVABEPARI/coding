#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return NULL;
        int ele = nums[0], cnt = 0, maxCnt = 0;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] == ele)
                cnt++;
            else
            {
                cnt--;
                if (cnt == 0)
                {
                    ele = nums[i];
                    cnt = 1;
                }
            }
        }
        return ele;
    }
};

int main()
{
    vector<int> arr = {7, 0, 0, 1, 7, 7, 2, 7, 7};
    Solution sol;
    cout << "majority Element -- " << sol.majorityElement(arr);
    return 0;
}