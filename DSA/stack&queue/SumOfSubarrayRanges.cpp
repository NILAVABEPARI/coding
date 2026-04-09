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
    vector<int> prevGreaterEqual(vector<int> &arr)
    {
        int n = arr.size();
        // !! store indices in stack
        stack<int> st;
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] < arr[i])
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
    vector<int> nextGreaterEle(vector<int> &arr)
    {
        // !! store indices in stack
        stack<int> st;
        int n = arr.size();
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] <= arr[i])
                st.pop();
            ans[i] = !st.empty() ? st.top() : n;
            st.push(i);
        }
        return ans;
    }

    int SumOfSubarrayMaxes(vector<int> &arr)
    {
        vector<int> pgee = prevGreaterEqual(arr);
        vector<int> nge = nextGreaterEle(arr);
        long long sum = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            int left = i - pgee[i], right = nge[i] - i;
            long long val = (1LL * left * right * arr[i]);
            sum = (sum + val);
        }
        return sum;
    }
    long long SumOfSubarrayMinis(vector<int> &arr)
    {
        vector<int> psee = prevSmallerEqual(arr);
        vector<int> nse = nextSmallerEle(arr);
        long long sum = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            int left = i - psee[i], right = nse[i] - i;
            long long val = (1LL * left * right * arr[i]);
            sum = (sum + val);
        }
        return sum;
    }

public:
    // brute force
    long long subArrayRanges(vector<int> &nums)
    {
        int n = nums.size();
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            int mini = nums[i], maxi = nums[i];
            for (int j = i; j < n; j++)
            {
                mini = min(mini, nums[j]);
                maxi = max(maxi, nums[j]);
                sum += (maxi - mini);
            }
        }
        return sum;
    }

    // optimal
    long long subArrayRanges2(vector<int> &nums)
    {
        return SumOfSubarrayMaxes(arr) - SumOfSubarrayMinis(arr);
    }
};

int main()
{
    vector<int> arr = {1, 2, 3};
    Solution sol;
    cout << "sum == " << sol.subArrayRanges2(arr);
    return 0;
}