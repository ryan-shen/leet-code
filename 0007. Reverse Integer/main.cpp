#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

/*
  時間複雜度：O(log10n)
*/
class Solution {
public:
    int reverse(int x) {
        //避免在將 x 轉成正數時溢位
        if (x == -2147483648) {
            return 0;
        }

        int sum = 0;
        int sign = x >= 0 ? 1 : -1;
        x *= (x >= 0) ? 1 : -1; //先把 x 轉為正數，不然等等取餘數會是負的

        while (x > 0) {
            //溢位了
            if (sum >= 214748365 || sum == 214748364 && x % 10 > 7) {
                return 0;
            }

            sum = sum * 10 + x % 10;
            x /= 10;
        }

        return sum * sign;
    }
};

int main(int argc, const char* argv[])
{
    Solution* solution = new Solution();
    int input = -2147483648;

    int result = solution->reverse(input);
    cout << result << endl;

    return 0;
}