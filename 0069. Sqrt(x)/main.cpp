#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

/*
  時間複雜度：O(logn)
*/
class Solution {
public:
    int mySqrt(int x) {
        //每次都從中間值找
        int left = 0;
        int right = x;
        unsigned long long int mid, square, square1;

        while (true) {
            mid = left + (right - left) / 2;
            square = mid * mid;

            if (square <= x) {
                square1 = (mid + 1) * (mid + 1);

                if (square1 < x) {
                    left = mid;
                    continue;
                }

                if (square1 > x) {
                    return mid;
                }

                return mid + 1;
            }

            right = mid;
        }
    }
};

int main(int argc, const char* argv[])
{
    Solution* solution = new Solution();
    int x = 1;

    int result = solution->mySqrt(x);
    cout << result << endl;

    return 0;
}