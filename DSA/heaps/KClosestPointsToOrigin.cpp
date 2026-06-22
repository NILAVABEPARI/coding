#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<pair<int, int>> pq;
        vector<vector<int>> ans;
        for (int i = 0; i < points.size(); i++)
        {
            int x = (points[i][0] * points[i][0] + points[i][1] * points[i][1]);
            pq.push({x, i});
            if (pq.size() > k)
                pq.pop();
        }
        while (!pq.empty())
        {
            int index = pq.top().second;
            pq.pop();
            ans.push_back(points[index]);
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> nums = {{3, 3}, {5, -1}, {-2, 4}};
    int k = 2;
    Solution sol;
    vector<vector<int>> ans = sol.kClosest(nums, k);
    cout << "minimum penalty -- " << endl;
    for (auto &it : ans)
    {
        cout << "[";
        for (auto &i : it)
            cout << i << ", ";
        cout << "]";
    }
    return 0;
}