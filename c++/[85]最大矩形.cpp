//给定一个仅包含 0 和 1 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。 
//
// 示例: 
//
// 输入:
//[
//  ["1","0","1","0","0"],
//  ["1","0","1","1","1"],
//  ["1","1","1","1","1"],
//  ["1","0","0","1","0"]
//]
//输出: 6 
// Related Topics 栈 数组 哈希表 动态规划 
// 👍 629 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0)
            return 0;
        int result = 0;
        vector<int> dp(matrix[0].size(), 0);
        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[i].size(); j++){
                dp[j] = matrix[i][j] == '1' ? dp[j]+1 : 0;
            }
            result = max(result, largestRectangleArea(dp));
        }
        return result;
    }

    int largestRectangleArea(vector<int>& heights) {
        int result = 0;
        stack<int> stack;
        heights.insert(heights.begin(), 0);
        heights.insert(heights.end(), 0);
        for (int i = 0; i < heights.size(); i++){
            while (!stack.empty() && heights[stack.top()] > heights[i]){
                int index = stack.top();
                stack.pop();
                int currentHeight = heights[index];
                int currentWidth = i - stack.top() - 1;
                result = max(result, currentHeight*currentWidth);
            }
            stack.push(i);
        }
        heights.pop_back();
        heights.erase(heights.begin());
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
