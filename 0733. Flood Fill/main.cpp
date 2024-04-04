#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

/*
  時間複雜度：O(n)
*/
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color) {
            return image;
        }

        dfs(image, sr, sc, color, image[sr][sc]);

        return image;
    }

    void dfs(vector<vector<int>>& image, int currentRow, int currentColumn, int color, int originalColor) {
        // 檢查是否超出邊界
        if (currentRow < 0 || currentColumn < 0 ||
            currentRow >= image.size() ||
            currentColumn >= image[currentRow].size()) {
            return;
        }

        // 只有跟 start 相同的顏色才需要上色
        if (image[currentRow][currentColumn] != originalColor) {
            return;
        }

        // 上色後遞迴檢查上下左右
        image[currentRow][currentColumn] = color;
        dfs(image, currentRow - 1, currentColumn, color, originalColor);
        dfs(image, currentRow, currentColumn - 1, color, originalColor);
        dfs(image, currentRow + 1, currentColumn, color, originalColor);
        dfs(image, currentRow, currentColumn + 1, color, originalColor);
    }
};