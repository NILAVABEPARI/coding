#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // optimal 1 --
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1, j = 0;
        while (i >= 0 && j < n)
        {
            if (nums1[i] > nums2[j])
                swap(nums1[i--], nums2[j++]);
            else
                break;
        }
        sort(nums1.begin(), nums1.begin() + m);
        sort(nums2.begin(), nums2.end());
        for (int k = 0; k < n; k++)
            nums1[m + k] = nums2[k];
    }

    // optimal 3 --
    void merge3(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1, j = n - 1, k = nums1.size() - 1;
        while (i >= 0 && j >= 0)
        {
            if (nums1[i] < nums2[j])
                nums1[k--] = nums2[j--];
            else
                nums1[k--] = nums1[i--];
        }
        while (j >= 0)
            nums1[k--] = nums2[j--];
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {-5, -2, 4, 5, 0, 0, 0}, nums2 = {-3, 1, 8};
    sol.merge(nums1, nums1.size() - nums2.size(), nums2, nums2.size());
    cout << "sorted array -- ";
    for (auto &it : nums1)
        cout << it << " ";
    return 0;
}