#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        unordered_set<int> st;
        for (int i = 0; i < nums.size(); i++)
            st.insert(nums[i]);
        int longest = 1;
        for (auto s : st)
        {
            // check if the current element is the smallest in the series
            if (st.find(s - 1) == st.end())
            {
                int cnt = 1;
                int x = s;
                while (st.find(x + 1) != st.end())
                {
                    cnt++;
                    x++;
                }
                longest = max(longest, cnt);
            }
        }
        return longest;
    }
};

int main()
{
    vector<int> a = {100, 4, 200, 1, 3, 2, 5, 6};

    // Create an instance of solution class
    Solution solution;
    // Function call for finding longest consecutive sequence
    int ans = solution.longestConsecutive(a);
    cout << "The longest consecutive sequence is " << ans << "\n";
    return 0;
}