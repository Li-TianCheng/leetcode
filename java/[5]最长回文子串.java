//给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。 
//
// 示例 1： 
//
// 输入: "babad"
//输出: "bab"
//注意: "aba" 也是一个有效答案。
// 
//
// 示例 2： 
//
// 输入: "cbbd"
//输出: "bb"
// 
// Related Topics 字符串 动态规划 
// 👍 2506 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public String longestPalindrome(String s) {
        //method 1
//        int length = s.length();
//        if(length == 0){
//            return "";
//        }
//        int end = length;
//        int start = 0;
//        int max = 0;
//        int[][] dp = new int[length][length];
//        for (int i = 0; i < length; i++) {
//            for (int j = 0; j < end; j++) {
//                if (i == 0) {
//                    dp[j][j] = 1;
//                    start = j;
//                    max = 1;
//                } else if (i == 1) {
//                    if (s.charAt(j) == s.charAt(j + 1)) {
//                        dp[j][j + 1] = 1;
//                        start = j;
//                        max = 2;
//                    }
//                } else {
//                    if ((s.charAt(j) == s.charAt(j + i)) && (dp[j + 1][j + i - 1] == 1)) {
//                        dp[j][j + i] = 1;
//                        start = j;
//                        max = i + 1;
//                    }
//                }
//            }
//            end--;
//        }
//        return s.substring(start, start + max);

        //method 2
        int length = s.length();
        if(length == 0){
            return "";
        }
        int start = 0, end = 0;
        for(int i=0; i < s.length(); i++){
            int len1 = expendAroundCenter(s, i, i);
            int len2 = expendAroundCenter(s, i, i+1);
            int len = Math.max(len1, len2);
            if (len > (end - start)) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return  s.substring(start, end + 1);


    }

    private int expendAroundCenter(String s, int left, int right){
        int L = left, R = right;
        while (L >= 0 && R < s.length() && s.charAt(L) == s.charAt(R)){
            L--;
            R++;
        }
        return R - L - 1;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
