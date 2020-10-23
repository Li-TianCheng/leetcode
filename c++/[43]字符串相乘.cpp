//给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。 
//
// 示例 1: 
//
// 输入: num1 = "2", num2 = "3"
//输出: "6" 
//
// 示例 2: 
//
// 输入: num1 = "123", num2 = "456"
//输出: "56088" 
//
// 说明： 
//
// 
// num1 和 num2 的长度小于110。 
// num1 和 num2 只包含数字 0-9。 
// num1 和 num2 均不以零开头，除非是数字 0 本身。 
// 不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。 
// 
// Related Topics 数学 字符串 
// 👍 493 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string multiply(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int n = num1.size();
        int m = num2.size();
        int count = 0;
        string result;
        for (int i = 0; i < m+n+1; i++) {
            int c = 0;
            for (int k = 0; k < i+1; k++) {
                int c1 = k < n ? num1[k]-'0' : 0;
                int c2 = i-k < m ? num2[i-k]-'0' : 0;
                c = c + c1 * c2;
            }
            c = c + count;
            if (c >= 10){
                count = c / 10;
                c = c % 10;
            }else
                count = 0;
            result += (char)(c+'0');
        }
        reverse(result.begin(), result.end());
        int idx = 0;
        for (; idx < result.size()-1; idx++){
            if (result[idx] != '0')
                break;
        }
        return result.substr(idx);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
