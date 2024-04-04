#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

/*
  時間複雜度：O(n * log(log(n)))
*/
class Solution {
public:
    int countPrimes(int n) {
        // 小於等於 2 的數字不管，以免初始化 0 大小的陣列導致噴錯
        if (n <= 2) {
            return 0;
        }

        //  初始化質數表，先假設所有數字都是質數，之後再把不符合條件的數字設為 false
        bool isPrime[n];
        for (size_t i = 2; i < n; i++)
        {
            isPrime[i] = true;
        }

        // 逐一剔除不符合條件的數字
        for (size_t i = 2; i < n; i++)
        {
            // 如果已經是 false 表示在這之前已經有數字將其設為 false，就算再往下乘也因為包含相同因數所以可以推斷之後都早已經被設為 false
            if (isPrime[i] == false) {
                continue;
            }

            // 將兩倍以後的數字設為 false
            for (size_t j = 2; i * j < n; j++)
            {
                isPrime[i * j] = false;
            }
        }

        // 從質數表算出小於 n 的質數個數
        int count = 0;
        for (size_t i = 2; i < n; i++)
        {
            count += isPrime[i];
        }

        return count;
    }
};

int main(int argc, const char* argv[])
{
    Solution* solution = new Solution();
    int input = 2;

    int result = solution->countPrimes(input);
    cout << result << endl;

    return 0;
}