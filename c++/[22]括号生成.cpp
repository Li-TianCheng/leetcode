//数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。 
//
// 
//
// 示例： 
//
// 输入：n = 3
//输出：[
//       "((()))",
//       "(()())",
//       "(())()",
//       "()(())",
//       "()()()"
//     ]
// 
// Related Topics 字符串 回溯算法 
// 👍 1337 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if (n == 0)
            return result;
        dfs("", n, n, result);
        return result;
    }

    void dfs(const string& curStr, const int& left, const int& right, vector<string>& result) {
        if (left ==0 && right ==0) {
            result.push_back(curStr);
            return;
        }
        if (left > right)
            return;
        if (left > 0)
            dfs(curStr+"(", left-1, right, result);
        if (right > 0)
            dfs(curStr+")", left, right-1, result);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
