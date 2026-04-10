#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    string removeKDigits(string nums, int k)
    {
        stack<char> st;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && k && st.top() > nums[i])
            {
                k--;
                st.pop();
            }
            st.push(nums[i]);
        }
        while (!st.empty() && k)
        {
            k--;
            st.pop();
        }
        if (st.empty())
            return "0";
        string res = "";
        while (!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        while (res.size() > 0 && res.back() == '0')
            res.pop_back();
        if (res.empty())
            return "0";
        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{
    string nums = "541892";
    int k = 2;
    Solution sol;
    cout << "smallest number == " << sol.removeKDigits(nums, k);
    return 0;
}