#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // brute force -- store both the arrays in a 3rd array and find the median

    // better
    // double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    // {
    //     int n1 = nums1.size(), n2 = nums2.size(), cnt = 0, i = 0, j = 0, n = n1 + n2;
    //     int ind2 = n / 2, ind1 = ind2 - 1, ind1Ele = NULL, ind2Ele = NULL;
    //     while (i < n1 && j < n2)
    //     {
    //         if (nums1[i] < nums2[j])
    //         {
    //             if (cnt == ind1)
    //                 ind1Ele = nums1[i];
    //             if (cnt == ind2)
    //                 ind2Ele = nums1[i];
    //             i++;
    //             cnt++;
    //         }
    //         else
    //         {
    //             if (cnt == ind1)
    //                 ind1Ele = nums2[j];
    //             if (cnt == ind2)
    //                 ind2Ele = nums2[j];
    //             j++;
    //             cnt++;
    //         }
    //     }
    //     while (i < n1)
    //     {
    //         if (cnt == ind1)
    //             ind1Ele = nums1[i];
    //         if (cnt == ind2)
    //             ind2Ele = nums1[i];
    //         i++;
    //         cnt++;
    //     }
    //     while (j < n2)
    //     {
    //         if (cnt == ind1)
    //             ind1Ele = nums2[j];
    //         if (cnt == ind2)
    //             ind2Ele = nums2[j];
    //         j++;
    //         cnt++;
    //     }
    //     if (n % 2)
    //         return (double)((double)(ind1Ele + ind2Ele)) / 2.0;
    //     return (double)ind2Ele;
    // }

    // optimal -- binary search on the smaller array
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size(), n2 = nums2.size();
        if (n1 > n2)
            return findMedianSortedArrays(nums2, nums1);
        int l = 0, h = n1;
        while (l <= h)
        {
            int cut1 = l + (h - l) / 2;
            int cut2 = (n1 + n2 + 1) / 2 - cut1;
            // !! by adding 1 we are taking more elements on the left side hence we ensure that median will lie on the left and will be among l1 or l2
            // !! but if we dont add 1 then we are ensuring that more elements are on the right so median will be among r1 and r2 -> min(r1,r2)
            int l1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
            int l2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];
            int r1 = cut1 == n1 ? INT_MAX : nums1[cut1 - 1];
            int r2 = cut2 == n2 ? INT_MAX : nums2[cut2 - 1];
            if (l1 <= r2 && l2 <= r1)
            {
                if ((n1 + n2) % 2)
                    return (double)(max(l1, l2));
                else
                    return (double)((max(l1, l2) + min(r1, r2)) / 2.0);
            }
            if (l1 > r2)
                h = cut1 - 1;
            else
                l = cut1 + 1;
        }
        return 0.0;
    }
};

int main()
{
    vector<int> nums1, nums2;
    Solution s;
    s.findMedianSortedArrays(nums1, nums2);
    return 0;
}