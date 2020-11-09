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
    public int minimumTotal(List<List<Integer>> triangle) {
        int[] dp = new int[triangle.size()];
        for (int i = 0; i < triangle.size(); i++) {
            if (i == 0){
                dp[0] = triangle.get(0).get(0);
            }else{
                int[] temp = Arrays.copyOf(dp, i);
                for (int j = 0; j < i+1; j++) {
                    int num1 = j-1 < 0 ? Integer.MAX_VALUE :temp[j-1];
                    int num2 = j >= temp.length ? Integer.MAX_VALUE :temp[j];
                    dp[j] = Math.min(num1, num2)+triangle.get(i).get(j);
                }
            }
        }
        int result = Integer.MAX_VALUE;
        for (int i = 0; i < dp.length; i++){
            result = Math.min(result, dp[i]);
        }
        return result;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
