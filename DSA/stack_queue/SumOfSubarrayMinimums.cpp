#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    vector<int> prevSmallerEqual(vector<int> &arr)
    {
        int n = arr.size();
        // !! store indices in stack
        stack<int> st;
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            ans[i] = !st.empty() ? st.top() : -1;
            st.push(i);
        }
        return ans;
    }
    vector<int> nextSmallerEle(vector<int> &arr)
    {
        // !! store indices in stack
        stack<int> st;
        int n = arr.size();
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            ans[i] = !st.empty() ? st.top() : n;
            st.push(i);
        }
        return ans;
    }

public:
    // brute force
    int sumSubarrayMins(vector<int> &arr)
    {
        int mod = 1e9 + 7, n = arr.size(), sum = 0;
        for (int i = 0; i < n; i++)
        {
            int mini = arr[i];
            for (int j = i; j < n; j++)
            {
                mini = min(mini, arr[j]);
                sum += mini % mod;
            }
        }
        return sum;
    }

    // optimal
    int sumSubarrayMins2(vector<int> &arr)
    {
        vector<int> pse = prevSmallerEqual(arr);
        vector<int> nse = nextSmallerEle(arr);
        int sum = 0, mod = 1e9 + 7;
        for (int i = 0; i < arr.size(); i++)
        {
            int left = i - pse[i], right = nse[i] - i;
            int val = (1LL * left * right * arr[i]) % mod;
            sum = (sum + val) % mod;
        }
        return sum;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {3, 1, 2, 5};
    cout << "sum of minimum -- " << sol.sumSubarrayMins2(arr);
    return 0;
}
