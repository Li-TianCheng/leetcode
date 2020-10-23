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
// 👍 628 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public int maximalRectangle(char[][] matrix) {
        if (matrix.length == 0)
            return 0;
        int result = 0;
        int[] dp = new int[matrix[0].length];
        for (int i = 0; i < matrix.length; i++){
            for (int j = 0; j < matrix[i].length; j++){
                dp[j] = matrix[i][j] == '1' ? dp[j] + 1 : 0;
            }
            result = Math.max(result, largestRectangleArea(dp));
        }
        return result;
    }

    public int largestRectangleArea(int[] heights) {
        int result = 0;
        Stack<Integer> stack = new Stack<>();
        int[] newHeight = new int[heights.length+2];
        System.arraycopy(heights, 0, newHeight, 1, heights.length);
        heights = newHeight;
        for (int i = 0; i < heights.length; i++){
            while (!stack.isEmpty() && heights[stack.peek()] > heights[i]){
                int index = stack.pop();
                int currentHeight = heights[index];
                int currentWidth = i - stack.peek() - 1;
                result = Math.max(result, currentHeight*currentWidth);
            }
            stack.push(i);
        }
        return result;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
