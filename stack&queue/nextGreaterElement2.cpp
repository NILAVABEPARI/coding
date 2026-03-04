#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // brute force --
    // vector<int> nextGreaterElements(vector<int> arr)
    // {
    //     int n = arr.size();
    //     vector<int> ans(n, -1);
    //     for (int i = 0; i < n; i++)
    //     {
    //         for (iny j = 1; j < n; j++)
    //         {
    //             int ind = (j + i) % n;
    //             if (arr[ind] > arr[j])
    //             {
    //                 ans[i] = arr[ind];
    //                 break;
    //             }
    //         }
    //     }
    //     return ans;
    // }

    // optimal --
    vector<int> nextGreaterElements(vector<int> arr)
    {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;
        for (int i = 2 * n - 1; i >= 0; i--)
        {
            int ind = i % n;
            while (!st.empty() && st.top() <= arr[ind])
                st.pop();
            if (i < n)
            {
                if (st.empty())
                    ans[ind] = -1;
                else
                    ans[ind] = st.top();
            }
            st.push(arr[ind]);
        }
        return ans;
    }
};

int main()
{
    int n = 6;
    vector<int> arr = {5, 7, 1, 7, 6, 0};

    /* Creating an instance of
    Solution class */
    Solution sol;

    /* Function call to find the next greater element
    for each element in the circular array */
    vector<int> ans = sol.nextGreaterElements(arr);

    cout << "The next greater elements are: ";
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}