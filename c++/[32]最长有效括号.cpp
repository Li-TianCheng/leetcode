//给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。 
//
// 示例 1: 
//
// 输入: "(()"
//输出: 2
//解释: 最长有效括号子串为 "()"
// 
//
// 示例 2: 
//
// 输入: ")()())"
//输出: 4
//解释: 最长有效括号子串为 "()()"
// 
// Related Topics 字符串 动态规划 
// 👍 1000 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int longestValidParentheses(string s) {
        //method1 dynamic programming
//        int result = 0;
//        vector<int> dp(s.size(), 0);
//        for (int i = 1; i < s.size(); i++) {
//            if (s[i] == ')' && i - dp[i-1] > 0 && s[i-dp[i-1]-1] == '(')
//                dp[i] = i - dp[i-1] >=2 ? dp[i-1] + dp[i-dp[i-1]-2] + 2 : dp[i-1] + 2;
//            result = max(result, dp[i]);
//        }
//        return result;

        //method2 stack
        stack<int> stack;
        stack.push(-1);
        int result = 0;
        int length = 0;
        for (int i=0; i < s.size(); i++){
            if (s[i] == '(')
                stack.push(i);
            else{
                stack.pop();
                if (stack.empty())
                    stack.push(i);
                else
                    result = max(result, i - stack.top());
            }
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
