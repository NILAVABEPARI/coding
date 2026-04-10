#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // brute force
    vector<int> maxSlidingWindow(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> ans;
        for (int i = 0; i <= (n - k); i++)
        {
            int maxi = arr[i];
            for (int j = i; j < (i + k); j++)
                maxi = max(maxi, arr[j]);
            ans.push_back(maxi);
        }
        return ans;
    }

    // optimal --
    vector<int> maxSlidingWindow2(vector<int> &arr, int k)
    {
        deque<int> dq;
        int n = arr.size();
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (!dq.empty() && dq.front() <= (i - k))
                dq.pop_front();
            while (!dq.empty() && arr[dq.back()] <= arr[i])
                dq.pop_back();
            dq.push_back(i);
            if (i >= k - 1)
                ans.push_back(arr[dq.front()]);
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = {4, 0, -1, 3, 5, 3, 6, 8};
    int k = 3;
    Solution sol;
    cout << "max in window == " << endl;
    vector<int> ans = sol.maxSlidingWindow2(nums, k);
    for (auto &it : ans)
        cout << it << " ";
    return 0;
}