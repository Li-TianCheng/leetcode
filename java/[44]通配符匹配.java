//给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。 
//
// '?' 可以匹配任何单个字符。
//'*' 可以匹配任意字符串（包括空字符串）。
// 
//
// 两个字符串完全匹配才算匹配成功。 
//
// 说明: 
//
// 
// s 可能为空，且只包含从 a-z 的小写字母。 
// p 可能为空，且只包含从 a-z 的小写字母，以及字符 ? 和 *。 
// 
//
// 示例 1: 
//
// 输入:
//s = "aa"
//p = "a"
//输出: false
//解释: "a" 无法匹配 "aa" 整个字符串。 
//
// 示例 2: 
//
// 输入:
//s = "aa"
//p = "*"
//输出: true
//解释: '*' 可以匹配任意字符串。
// 
//
// 示例 3: 
//
// 输入:
//s = "cb"
//p = "?a"
//输出: false
//解释: '?' 可以匹配 'c', 但第二个 'a' 无法匹配 'b'。
// 
//
// 示例 4: 
//
// 输入:
//s = "adceb"
//p = "*a*b"
//输出: true
//解释: 第一个 '*' 可以匹配空字符串, 第二个 '*' 可以匹配字符串 "dce".
// 
//
// 示例 5: 
//
// 输入:
//s = "acdcb"
//p = "a*c?b"
//输出: false 
// Related Topics 贪心算法 字符串 动态规划 回溯算法 
// 👍 503 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public boolean isMatch(String s, String p) {
        int length_s = s.length();
        int length_p = p.length();
        boolean[][] result = new boolean[length_s + 1][length_p + 1];
        result[0][0] = true;
        for (int j = 1; j < length_p + 1; j++){
            if (p.charAt(j - 1) != '*')
                result[0][j] = false;
            else
                result[0][j] = result[0][j - 1];
        }
        for (int i = 1; i < length_s + 1; i++){
            for (int j = 1; j < length_p + 1; j++){
                if (p.charAt(j - 1) != '*'){
                    if (Match(s.charAt(i - 1), p.charAt(j - 1)))
                        result[i][j] = result[i - 1][j - 1];
                    else
                        result[i][j] = false;
                }else {
                    result[i][j] = result[i - 1][j] || result[i][j - 1];
                }
            }
        }
        return result[length_s][length_p];
    }

    private boolean Match(char s, char p){
        if (p == '*' || p == '?'){
            return true;
        }else
            return p == s;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
