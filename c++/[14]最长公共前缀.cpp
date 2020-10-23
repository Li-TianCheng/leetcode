//编写一个函数来查找字符串数组中的最长公共前缀。 
//
// 如果不存在公共前缀，返回空字符串 ""。 
//
// 示例 1: 
//
// 输入: ["flower","flow","flight"]
//输出: "fl"
// 
//
// 示例 2: 
//
// 输入: ["dog","racecar","car"]
//输出: ""
//解释: 输入不存在公共前缀。
// 
//
// 说明: 
//
// 所有输入只包含小写字母 a-z 。 
// Related Topics 字符串 
// 👍 1281 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
            return "";
        int len = INT32_MAX;
        int index = 0;
        for (int i = 0; i < strs.size(); ++i) {
            if (strs[i].size() < len){
                len = strs[i].size();
                index = i;
            }
        }
        for (int i = 0; i < len; ++i) {
            char c = strs[index][i];
            for (int j = 0; j < strs.size(); ++j) {
                if (strs[j][i] != c)
                    return strs[index].substr(0, i);
            }
        }
        return strs[index];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
