class Solution
{
public:
    vector<int> preGreaterEle(vector<int> &arr)
    {
        //  code here
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n, -1);
        st.push(arr[0]);
        for (int i = 1; i < n; i++)
        {
            while (!st.empty() && st.top() <= arr[i])
                st.pop();
            if (!st.empty())
                ans[i] = st.top();
            st.push(arr[i]);
        }
        return ans;
    }
};