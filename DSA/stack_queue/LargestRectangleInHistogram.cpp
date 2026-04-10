#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<int> findNSE(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> nse(n);
        // store the indices
        stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && heights[(size_t)st.top()] >= heights[i])
                st.pop();
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> findPSE(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> pse(n);
        // store the indices
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && heights[(size_t)st.top()] >= heights[i])
                st.pop();
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }

public:
    // brute force
    int largestRectangleArea(vector<int> &heights)
    {
        vector<int> nse = findNSE(heights);
        vector<int> pse = findPSE(heights);
        int maxArea = INT_MIN;
        for (int i = 0; i < heights.size(); i++)
        {
            int width = nse[i] - pse[i] - 1;
            maxArea = max(maxArea, width * heights[i]);
        }
        return maxArea;
    }

    // optimal --
    int largestRectangleArea2(vector<int> &heights)
    {
        int n = (int)heights.size(), area = INT_MIN, nse, pse;
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && heights[(size_t)st.top()] >= heights[i])
            {
                // consider the area for the element in the top of stack
                int ind = st.top();
                st.pop();

                // for the top of the stack, it is being removed means the current element is smaller than it
                nse = i;
                // if the stack becomes empty then the previous smaller element is -1 else the top of stack because the stack is in monotonic increasing order
                pse = st.empty() ? -1 : st.top();
                area = max(area, heights[ind] * (nse - pse - 1));
            }
            st.push(i);
        }
        // for the elements remaining in stack which were not popper -- monotonic increasing order
        while (!st.empty())
        {
            int ind = st.top();
            st.pop();
            nse = n;
            pse = st.empty() ? -1 : st.top();
            area = max(area, heights[ind] * (nse - pse - 1));
        }
        return area;
    }
};

int main()
{
    vector<int> arr = {3, 5, 1, 7, 5, 9};
    Solution sol;
    cout << "largest rectangle == " << sol.largestRectangleArea2(arr);
    return 0;
}