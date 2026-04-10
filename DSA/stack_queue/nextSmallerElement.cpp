#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> nextSmallerEle(vector<int> &arr)
    {
        stack<int> st;
        int n = arr.size();
        st.push(arr[n - 1]);
        vector<int> ans(n, -1);
        for (int i = n - 2; i >= 0; i--)
        {
            while (!st.empty() && st.top() >= arr[i])
                st.pop();
            if (!st.empty())
                ans[i] = st.top();
            st.push(arr[i]);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {4, 8, 5, 2, 25};
    cout << "sum of minimum -- " << sol.nextSmallerEle(arr);
    return 0;
}