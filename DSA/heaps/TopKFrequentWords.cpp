#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

struct Compare
{
    bool operator()(pair<int, string> a, pair<int, string> b)
    {
        if (a.first == b.first)
            return a.second > b.second;
        else
            return a.first < b.first;
    }
};

class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        vector<string> ans;
        priority_queue<pair<int, string>, vector<pair<int, string>>, Compare> pq;
        unordered_map<string, int> mp;
        for (auto &it : words)
            mp[it]++;
        for (auto &it : mp)
            pq.push({it.second, it.first});
        while (k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }

    // without using priority_queue
    vector<string> topKFrequent2(vector<string> &words, int k)
    {
        unordered_map<string, int> mp;
        for (auto &w : words)
            mp[w]++;

        vector<pair<string, int>> v(mp.begin(), mp.end());
        sort(v.begin(), v.end(), [](auto &a, auto &b)
             {
            if (a.second == b.second)
                return a.first < b.first;
            return a.second > b.second; });

        vector<string> ans;
        for (int i = 0; i < k; i++)
            ans.push_back(v[i].first);

        return ans;
    }
};

int main()
{
    vector<string> nums = {"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"};
    int k = 2;
    Solution sol;
    vector<string> ans = sol.topKFrequent(nums, k);
    cout << "top k frequent words -- " << endl;
    for (auto &it : ans)
        cout << it << " ";
    return 0;
}