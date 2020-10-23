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
// 👍 2675 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string longestPalindrome(string s) {
        int length = s.size();
        if (length == 0){
            return "";
        }
        int start = 0;
        int end = 0;
        for (int i = 0; i < length; ++i) {
            int len1 = expendAroundCenter(s, i, i);
            int len2 = expendAroundCenter(s, i, i + 1);
            int len = max(len1, len2);
            if (len > (end - start)){
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substr(start, end - start + 1);
    }

private:
    int expendAroundCenter(string s, int left, int right){
        int L = left;
        int R = right;
        while (L >= 0 && R < s.size() && s[L] == s[R]){
            L--;
            R++;
        }
        return R - L - 1;
    }
};

//class Solution {
//public:
//    string longestPalindrome(string s) {
//        int length = s.size();
//        if (length == 0){
//            return "";
//        }
//        int end = length;
//        int start = 0;
//        int max = 0;
//        vector<vector<int>> dp(length, vector<int>(length));
//        for (int i = 0; i < length; ++i) {
//            for (int j = 0; j < end; ++j) {
//                if (i == 0){
//                    dp[j][j] = 1;
//                    start = j;
//                    max = 1;
//                } else if (i == 1){
//                    if (s[j] == s[j + 1]){
//                        dp[j][j + 1] = 1;
//                        start = j;
//                        max = 2;
//                    }
//                } else{
//                    if (s[j] == s[j + i] && dp[j + 1][j + i - 1] == 1){
//                        dp[j][j + i] = 1;
//                        start = j;
//                        max = i + 1;
//                    }
//                }
//            }
//            end--;
//        }
//        return s.substr(start, max);
//    }
//};
//leetcode submit region end(Prohibit modification and deletion)
