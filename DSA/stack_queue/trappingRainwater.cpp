#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findLeftMax(vector<int> &height)
    {
        int n = height.size();
        vector<int> ans(n, 0);
        ans[0] = height[0];
        for (int i = 1; i < n; i++)
            ans[i] = max(ans[i - 1], height[i]);
        return ans;
    }
    vector<int> findRightMax(vector<int> &height)
    {
        int n = height.size();
        vector<int> ans(n, 0);
        ans[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--)
            ans[i] = max(ans[i + 1], height[i]);
        return ans;
    }
    int trap(vector<int> &height)
    {
        vector<int> leftMax = findLeftMax(height);
        vector<int> rightMax = findRightMax(height);
        int n = height.size(), water = 0;
        for (int i = 1; i < n - 1; i++)
        {
            if (height[i] < leftMax[i] && height[i] < rightMax[i])
                water += min(leftMax[i], rightMax[i]) - height[i];
        }
        return water;
    }
};

int main()
{
    vector<int> arr = {7, 4, 0, 9};
    Solution sol;
    cout << "rainwater trapped -- " << sol.trap(arr);
    return 0;
}