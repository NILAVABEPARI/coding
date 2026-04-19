#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isPalindrome(int n)
    {
        int temp = n, newNum = 0;
        while (n)
        {
            int dig = n % 10;
            n /= 10;
            newNum = (newNum * 10) + dig;
        }
        return temp == newNum;
    }
    bool isDigitSumPalindrome(int n)
    {
        // code here
        int sum = 0;
        while (n)
        {
            sum += n % 10;
            n /= 10;
        }
        return isPalindrome(sum);
    }
};

int main()
{
    Solution sol;
    cout << "is palindrome -- " << sol.isDigitSumPalindrome(56);
    return 0;
}