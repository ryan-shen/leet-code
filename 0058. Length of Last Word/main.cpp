#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

/*
  時間複雜度：O(n)
  空間複雜度：O(1)
*/
class Solution {
public:
    int lengthOfLastWord(string s) {
        // 用來儲存最後一個單字的長度
        int length = 0;

        for (auto it = s.rbegin(); it < s.rend(); it++) {
            if (*it == ' ') {
                // 跳過結尾的空白字元
                if (length == 0) {
                    continue;
                }

                // 已在最後一個單字前面找到空白字元，直接回傳答案
                break;
            }

            length++;
        }

        return length;
    }
};

int main(int argc, const char* argv[])
{
    Solution* solution = new Solution();
    string input = "   fly me   to   the moon ";

    int result = solution->lengthOfLastWord(input);
    cout << result << endl;

    return 0;
}