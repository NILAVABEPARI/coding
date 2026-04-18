#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // this is called digital root of a number
    int addDigits(int num)
    {
        if (num == 0)
            return 0;
        if (num % 9 == 0)
            return 9;
        return num % 9;
    }
};