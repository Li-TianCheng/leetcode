//给你两个二进制字符串，返回它们的和（用二进制表示）。 
//
// 输入为 非空 字符串且只包含数字 1 和 0。 
//
// 
//
// 示例 1: 
//
// 输入: a = "11", b = "1"
//输出: "100" 
//
// 示例 2: 
//
// 输入: a = "1010", b = "1011"
//输出: "10101" 
//
// 
//
// 提示： 
//
// 
// 每个字符串仅由字符 '0' 或 '1' 组成。 
// 1 <= a.length, b.length <= 10^4 
// 字符串如果不是 "0" ，就都不含前导零。 
// 
// Related Topics 数学 字符串 
// 👍 498 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string addBinary(string a, string b) {
        int n = max(a.size(), b.size());
        string result;
        int sign = 0;
        for (int i = 0; i < n; ++i){
            int c1 = i < a.size() ? a[a.size()-i-1]-'0' : 0;
            int c2 = i < b.size() ? b[b.size()-i-1]-'0' : 0;
            int re = (c1 + c2 + sign) % 2 + '0';
            result += (char)re;
            sign = (c1 + c2 + sign) >> 1;
        }
        if (sign == 1)
            result += (char)(1+'0');
        reverse(result.begin(), result.end());
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
