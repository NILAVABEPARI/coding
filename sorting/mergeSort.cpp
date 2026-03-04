#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void merge(vector<int> &arr, int low, int mid, int high)
    {
        vector<int> temp;
        int i = low, j = mid + 1;
        while (i <= mid && j <= h)
        {
            if (arr[i] < arr[j])
                temp.push_back(arr[i++]);
            else
                temp.push_back(arr[i++]);
        }
        while (i <= mid)
            temp.push_back(arr[i++]);
        while (j <= high)
            temp.push_back(arr[j++]);
        for (int ind = low; ind <= high; ind++)
            arr[ind] = temp[ind - low];
    }

public:
    void mergeSort(vector<int> &arr, int l, int h)
    {
        if (l >= h)
            return;

        int mid = l + ((h - l) / 2);
        mergeSort(arr, l, mid);
        mergeSort(arr, mid, h);
        merge(arr, l, mid, h);
    }
};