#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int largestRectangleArea(vector<int> &heights)
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

public:
    int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size(), maxArea = 0;
        vector<int> heights(m, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0)
                    heights[j] = 0;
                else
                    heights[j]++;
            }
            maxArea = max(maxArea, largestRectangleArea(heights));
        }
        return maxArea;
    }
};

int main()
{
    vector<vector<int>> arr = {{1, 0, 1, 0, 0}, {1, 0, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 0, 0, 1, 0}};
    Solution sol;
    cout << "maximum rectangles -- " << sol.maximalAreaOfSubMatrixOfAll1(arr);
    return 0;
}