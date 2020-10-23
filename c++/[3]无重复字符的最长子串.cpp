//给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。 
//
// 示例 1: 
//
// 输入: "abcabcbb"
//输出: 3 
//解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
// 
//
// 示例 2: 
//
// 输入: "bbbbb"
//输出: 1
//解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
// 
//
// 示例 3: 
//
// 输入: "pwwkew"
//输出: 3
//解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
//     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
// 
// Related Topics 哈希表 双指针 字符串 Sliding Window 
// 👍 4306 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> occ;
        int n = s.size();
        int index = -1;
        int result = 0;
        for (int i = 0; i < n; ++i) {
            while (true){
                if (index + 1 < s.length()){
                    index++;
                }
                if (!occ.count(s[index])){
                    occ.insert(s[index]);
                    result = max(index - i + 1, result);
                } else{
                    index--;
                    occ.erase(s[i]);
                    break;
                }
            }
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
