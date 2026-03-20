class Solution
{
    int canBePlaced(vector<int> arr, int dist, int k)
    {
        int last = arr[0], cows = 1;
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] - last >= dist)
            {
                cows++;
                last = arr[i];
            }
        }
        return cows >= k
    }

public:
    int aggressiveCows(vector<int> &arr, int k)
    {
        sort(arr.begin(), arr.end());
        int mini = arr[0], maxi = arr[arr.size() - 1];
        // for (int i = 1; i <= (maxi - mini); i++)
        // {
        //     if (!canBePlaced(arr, i, k))
        //         return i - 1;
        // }
        // return maxi - mini;

        int l = 1, h = maxi - mini;
        while (l <= h)
        {
            int mid = l + (h - l) / 2;
            if (canBePlaced(arr, mid, k))
                l = mid + 1;
            else
                h = mid - 1;
        }
    }
};