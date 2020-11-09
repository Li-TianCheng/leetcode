//给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。 
//
// 相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。 
//
// 
//
// 例如，给定三角形： 
//
// [
//     [2],
//    [3,4],
//   [6,5,7],
//  [4,1,8,3]
//]
// 
//
// 自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。 
//
// 
//
// 说明： 
//
// 如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。 
// Related Topics 数组 动态规划 
// 👍 638 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp(triangle.size(), 0);
        for (int i = 0; i < triangle.size(); i++){
            if (i == 0) {
                dp[0] = triangle[0][0];
            }else{
                vector<int> temp;
                temp.assign(dp.begin(), dp.begin()+i);
                for (int j = 0; j < i+1; j++){
                    int num1 = j-1 < 0 ? INT32_MAX :temp[j-1];
                    int num2 = j >= temp.size() ? INT32_MAX :temp[j];
                    dp[j] = min(num1, num2) + triangle[i][j];
                }
            }
        }
        int result = INT32_MAX;
        for (int i = 0; i < dp.size(); i++){
            result = min(result, dp[i]);
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
