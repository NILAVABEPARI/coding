#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> threeSum(vector<int> arr)
    {
        int n = arr.size();
        for (int i = 0; i < n - 2; i++)
        {
            if (i != 0 && arr[i] == arr[i - 1])
                continue;
            int j = i + 1, k = n - 1;
            while (j < k)
            {
                int sum = arr[i] + arr[j] + arr[k];
                if (sum < 0)
                {
                    j++;
                }
                else if (sum > 0)
                    k--;
                else
                {
                    ans.push_back({arr[i], arr[j], arr[k]});
                    j++;
                    k--;
                    while (j < k && arr[j] == arr[j - 1])
                        j++;
                    while (j < k && arr[k] == arr[k + 1])
                        k--;
                }
            }
        }
    }
};

int main()
{
    Solution s;
    vector<int> arr(2, 1, 5, 4, 3, 0, 0);
    vector<int> ans;
    ans = s.threeSum(arr);
    return 0;
}