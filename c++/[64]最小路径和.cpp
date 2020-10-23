//给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。 
//
// 说明：每次只能向下或者向右移动一步。 
//
// 示例: 
//
// 输入:
//[
//  [1,3,1],
//  [1,5,1],
//  [4,2,1]
//]
//输出: 7
//解释: 因为路径 1→3→1→1→1 的总和最小。
// 
// Related Topics 数组 动态规划 
// 👍 696 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < m; ++i)
            dp[i][0] = dp[i-1][0] + grid[i][0];
        for (int i = 1; i < n; ++i)
            dp[0][i] = dp[0][i-1] + grid[0][i];
        for (int k = 1; k < min(m, n); k++){
            for (int i = k; i < m; i++)
                dp[i][k] = min(dp[i-1][k], dp[i][k-1]) + grid[i][k];
            for (int i = k; i < n; i++)
                dp[k][i] = min(dp[k][i-1], dp[k-1][i]) + grid[k][i];
        }
        return dp[m-1][n-1];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
