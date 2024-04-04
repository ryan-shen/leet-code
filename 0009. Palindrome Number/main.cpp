#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

/*
  時間複雜度：O(n)
*/
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0) {
            return false;
        }

        if (x < 10) {
            return true;
        }

        int n = 1;
        int length = floor(log10(x)) + 1; //數字總共幾位數
        int m = pow(10, length - 1);
        while (n < m) { //只要解析位數的一半次就好
            int leftDigit = x / m % 10; //從左邊數來的位元
            int rightDigit = x / n % 10; //從右邊數來的位元

            if (leftDigit != rightDigit) {
                return false;
            }
            n *= 10;
            m /= 10;
        }

        return true;
    }
};

int main(int argc, const char* argv[])
{
    Solution* solution = new Solution();
    int x = 1000000001;

    bool result = solution->isPalindrome(x);
    cout << result << endl;

    return 0;
}