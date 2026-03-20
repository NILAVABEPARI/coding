#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findUnion(vector<int> &a, vector<int> &b)
    {
        vector<int> ans;
        int n = a.size(), m = b.size(), i = 0, j = 0;
        while (i < n && j < m)
        {
            if (a[i] <= b[j])
            {
                if (ans.size() == 0 || ans.back() < a[i])
                    ans.push_back(a[i]);
                i++;
            }
            else
            {
            }
        }
        while (i < n)
        {
            if (ans.back() < a[i])
            {
                ans.push_back(a[i]);
            }
            i++;
        }
        return ans;
    }
};

int main()
{

    return 0;
}