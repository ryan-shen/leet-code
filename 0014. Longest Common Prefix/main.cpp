#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

/*
  時間複雜度：O(nlogn)
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // 透過事先排序避免處理最長字串後結果發現無效的情境
        sort(strs.begin(), strs.end());

        int size = strs.size();

        if (size == 0 || strs[0] == "") {
            return "";
        }

        // 因為已經排序過，所以只要比第一個跟最後一個就好了（因為一樣的部分跟其他字串一定也一樣）
        string longestCommonPrefix = "";

        for (size_t i = 0; i < strs[0].length(); i++)
        {
            if (strs[0][i] != strs[size - 1][i]) {
                return longestCommonPrefix;
            }

            longestCommonPrefix.push_back(strs[0][i]);
        }

        return longestCommonPrefix;
    }
};

int main(int argc, const char* argv[])
{
    Solution* solution = new Solution();
    vector<string> vec;
    vec.push_back("flower");
    vec.push_back("flow");
    vec.push_back("flight");

    string result = solution->longestCommonPrefix(vec);
    cout << result << endl;

    return 0;
}