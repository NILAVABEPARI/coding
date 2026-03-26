#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    // optimal if array has both negatives and positives
    int longestSubarray(vector<int> &arr, int k)
    {
        unordered_map<int, int> mp;
        int len = 0;
        long long sum = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            sum += arr[i];
            if (sum == k)
                len = max(len, i + 1);
            int remain = sum - k;
            if (mp.find(remain) != mp.end())
                len = max(len, i - mp[remain]);
            if (mp.find(sum) == mp.end())
                mp[sum] = i;
        }
        return len;
    }

    // optimal -- if the array has only positives
    int longestSubarray2(vector<int> &arr, int k)
    {
        int n = arr.size();
        int left = 0, right = 0, len = 0;
        long long sum = 0;
        while (right < n)
        {
            sum += arr[right];
            if (sum == k)
                len = max(len, right - left + 1);
            while (left <= right && sum > k)
                sum -= arr[left++];
            right++;
        }
        return len;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {10, 5, 2, 7, 1, 9};
    int ans = sol.longestSubarray2(arr, 15);
    cout << "ans -- " << ans;
    return 0;
}