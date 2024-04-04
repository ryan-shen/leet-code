#include <iostream>
#include <vector>
using namespace std;

/*
  時間複雜度：O(n)
*/
class Solution
{
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse_iterator iterator = digits.rbegin();
        while (true) {
            //該位數 + 1
            (*iterator)++;

            //沒進位的情況
            if (*iterator != 10) {
                return digits;
            }

            //進位的情況
            *iterator = 0;
            iterator++;

            //已經在首位卻還需要進位的情況
            if (iterator == digits.rend()) {
                digits.insert(digits.begin(), 1);
                return digits;
            }
        }
    }
};

int main(int argc, const char* argv[])
{
    Solution* solution = new Solution();
    vector<int> digits = { 1,2,3 };

    vector<int> result = solution->plusOne(digits);
    for (auto&& i : result)
    {
        cout << i << ' ';
    }

    return 0;
}