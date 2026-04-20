#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        int low = 0, high = letters.size() - 1;
        char c = letters[0];
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (letters[mid] > target)
            {
                c = letters[mid];
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return c;
    }
};

int main()
{
    Solution sol;
    vector<char> letters = {'c', 'f', 'j'};
    cout << "smallest character -- " << sol.nextGreatestLetter(letters, 'g');
    return 0;
}