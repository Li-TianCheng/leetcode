//给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。 
//
// 有效的 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。 
//
// 例如："0.1.2.201" 和 "192.168.1.1" 是 有效的 IP 地址，但是 "0.011.255.245"、"192.168.1.312"
// 和 "192.168@1.1" 是 无效的 IP 地址。 
//
// 
//
// 示例 1： 
//
// 输入：s = "25525511135"
//输出：["255.255.11.135","255.255.111.35"]
// 
//
// 示例 2： 
//
// 输入：s = "0000"
//输出：["0.0.0.0"]
// 
//
// 示例 3： 
//
// 输入：s = "1111"
//输出：["1.1.1.1"]
// 
//
// 示例 4： 
//
// 输入：s = "010010"
//输出：["0.10.0.10","0.100.1.0"]
// 
//
// 示例 5： 
//
// 输入：s = "101023"
//输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
// 
//
// 
//
// 提示： 
//
// 
// 0 <= s.length <= 3000 
// s 仅由数字组成 
// 
// Related Topics 字符串 回溯算法 
// 👍 445 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public List<String> restoreIpAddresses(String s) {
        List<String> result = new ArrayList<>();
        StringBuffer sb = new StringBuffer();
        backtrace(s, sb, 0, 0, result);
        return result;
    }

    private void backtrace(String s, StringBuffer sb, int start, int n, List<String> result) {
        if (sb.length() == s.length()+4 && n == 4) {
            sb.delete(sb.length()-1, sb.length());
            result.add(sb.toString());
            sb.append('.');
            return;
        }
        if ((4-n)*3 < s.length()-sb.length()+n)
            return;
        int m = Math.min(3, s.length()-start);
        for (int i = start; i < start+m; i++) {
            String tem = s.substring(start, i+1);
            if (isValid(tem)){
                sb.append(tem);
                sb.append('.');
                backtrace(s, sb, i+1, n+1, result);
                sb.delete(sb.length()-1, sb.length());
                sb.delete(sb.length()-i+start-1, sb.length());
            }else
                return;
        }
    }

    private boolean isValid(String s) {
        int num = 0;
        for (int i = 0; i < s.length(); i++) {
            num += (s.charAt(i) - '0') * Math.pow(10, s.length() - i - 1);
        }
        if (num >= 0 && num < 10)
            return s.length() == 1;
        if (num >= 10 && num < 100)
            return s.length() == 2;
        if (num >= 100 && num <= 255)
            return s.length() == 3;
        return false;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
