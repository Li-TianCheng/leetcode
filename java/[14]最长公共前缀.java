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
// 👍 1201 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public String longestCommonPrefix(String[] strs) {
        if(strs.length == 0)
            return "";
        int len = Integer.MAX_VALUE;
        int index = 0;
        for(int i=0; i < strs.length; i++){
            if(strs[i].length() < len){
                len = strs[i].length();
                index = i;
            }
        }
        for(int i=0; i < len; i++){
            char c = strs[index].charAt(i);
            for(int j=0; j < strs.length; j++){
                if(strs[j].charAt(i) != c)
                    return strs[index].substring(0, i);
            }
        }
        return strs[index];
    }
}
//leetcode submit region end(Prohibit modification and deletion)
