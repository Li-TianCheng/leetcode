//给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。 
//
// 返回符合要求的最少分割次数。 
//
// 示例: 
//
// 输入: "aab"
//输出: 1
//解释: 进行一次分割就可将 s 分割成 ["aa","b"] 这样两个回文子串。
// 
// Related Topics 动态规划 
// 👍 223 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public int minCut(String s) {
        int n = s.length();
        int[] dp = new int[n];
        for (int i = 0; i < n; i++) {
            dp[i] = i;
        }
        for (int i = 1; i < n; i++) {
            if (isValid(s, 0, i)){
                dp[i] = 0;
                continue;
            }
            for (int j = 0; j < i; j++) {
                if (isValid(s, j+1, i)){
                    dp[i] = Math.min(dp[i], dp[j]+1);
                }
            }
        }
        return dp[n-1];
    }

    private boolean isValid(String s, int left, int right) {
        while (left < right) {
            if (s.charAt(left) != s.charAt(right)){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
