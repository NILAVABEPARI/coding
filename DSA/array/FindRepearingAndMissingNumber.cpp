#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums)
    {
        long long sum = 0, mul = 0;
        for (auto &it : nums)
        {
            sum += it;
            mul += (long long)it * (long long)it;
        }
        long long n = nums.size();
        long long sumOfN = (n * (n + 1)) / 2, mulOfN = (n * (n + 1) * ((2 * n) + 1)) / 6;
        // !! val2 == repeating^2 - missing^2 == x^2 - y^2
        // !! val1 == sum - sumOfN == repeating - missing == x - y
        long long val1 = sum - sumOfN, val2 = mul - mulOfN;

        // x^2 - y^2 = (x + y)(x - y)
        // !! val2 = x + y
        val2 = val2 / val1;

        long long repeating = (val1 + val2) / 2;
        long long missing = repeating - val1;
        return {(int)repeating, (int)missing};
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {6, 5, 7, 1, 8, 6, 4, 3, 2};
    vector<int> ans = sol.findMissingRepeatingNumbers(arr);
    for (auto &it : ans)
        cout << it << ", ";
    return 0;
}