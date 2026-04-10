#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> stockSpan(vector<int> arr, int n)
    {
        // store the indices
        stack<int> st;
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] <= arr[i])
                st.pop();
            ans[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }
        return ans;
    }
};

int main()
{
    vector<int> arr = {120, 100, 60, 80, 90, 110, 115};
    Solution sol;
    cout << "stock span -- " << endl;
    vector<int> ans = sol.stockSpan(arr, arr.size());
    for (auto &it : ans)
        cout << it << " ";
    return 0;
}