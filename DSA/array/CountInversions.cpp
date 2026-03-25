#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    long long int merge(vector<int> &nums, int low, int mid, int high)
    {
        vector<int> temp;
        int left = low, right = mid + 1;
        long long int cnt = 0;
        while (left <= mid && right <= high)
        {
            if (nums[left] <= nums[right])
                temp.push_back(nums[left++]);
            else
            {
                cnt += (mid - left + 1);
                temp.push_back(nums[right++]);
            }
        }
        while (left <= mid)
            temp.push_back(nums[left++]);
        while (right <= high)
            temp.push_back(nums[right++]);
        for (int i = 0; i < temp.size(); i++)
            nums[low + i] = temp[i];
        return cnt;
    }
    long long int mergeSort(vector<int> &nums, int low, int high)
    {
        long long int cnt = 0;
        if (low < high)
        {
            int mid = low + ((high - low) / 2);
            cnt += mergeSort(nums, low, mid);
            cnt += mergeSort(nums, mid + 1, high);
            cnt += merge(nums, low, mid, high);
        }
        return cnt;
    }

public:
    // brute force
    long long int numberOfInversions(vector<int> &nums)
    {
        int n = nums.size();
        long long cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] > nums[j])
                    cnt++;
            }
        }
        return cnt;
    }

    // optimal -- using merge sort
    long long int numberOfInversions2(vector<int> &nums)
    {
        int n = nums.size();
        return mergeSort(nums, 0, n - 1);
    }
};

int main()
{
    vector<int> arr = {2, 3, 7, 1, 3, 5};
    Solution sol;
    long long int result = sol.numberOfInversions2(arr);
    cout << "inversion count == " << result;
    return 0;
}