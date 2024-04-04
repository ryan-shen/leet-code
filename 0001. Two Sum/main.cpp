#include <iostream>
#include <vector>
using namespace std;

/*
  時間複雜度：O(n^2)
*/
class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target) {
                    vector<int> vec = { i, j };
                    return vec;
                }
            }
        }

        return nums;
    }
};

int main(int argc, const char* argv[])
{
    Solution* solution = new Solution();
    vector<int> nums = { 2,7,11,15 };
    int target = 9;

    vector<int> result = solution->twoSum(nums, target);
    for (auto&& i : result)
    {
        cout << i << ' ';
    }

    return 0;
}