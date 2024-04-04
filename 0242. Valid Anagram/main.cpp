#include <iostream>
#include <vector>
#include <math.h>
#include <map>
using namespace std;

/*
  時間複雜度：O(n)
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        int occurrence[123] = { 0 };

        for (auto it = s.begin(); it != s.end(); it++) {
            occurrence[*it]++;
        }

        for (auto it = t.begin(); it != t.end(); it++) {
            occurrence[*it]--;
        }

        // 依照題目指示，只關注 a ~ z 的 ASCII
        for (size_t i = 97; i < 123; i++)
        {
            if (occurrence[i] != 0) {
                return false;
            }
        }

        return true;
    }
};

int main(int argc, const char* argv[])
{
    Solution* solution = new Solution();
    string s = "rat";
    string t = "car";

    int result = solution->isAnagram(s, t);
    cout << result << endl;

    return 0;
}