//找到给定字符串（由小写字符组成）中的最长子串 T ， 要求 T 中的每一字符出现次数都不少于 k 。输出 T 的长度。 
//
// 示例 1: 
//
// 
//输入:
//s = "aaabb", k = 3
//
//输出:
//3
//
//最长子串为 "aaa" ，其中 'a' 重复了 3 次。
// 
//
// 示例 2: 
//
// 
//输入:
//s = "ababbc", k = 2
//
//输出:
//5
//
//最长子串为 "ababb" ，其中 'a' 重复了 2 次， 'b' 重复了 3 次。
// 
// Related Topics 递归 分治算法 Sliding Window 
// 👍 274 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int longestSubstring(string s, int k) {
        if (s.size() < k){
            return 0;
        }
        unordered_map<char, int> map;
        for (char& c : s) {
            map[c]++;
        }
        vector<int> split;
        for (int i = 0; i < s.size(); i++) {
            if (map[s[i]] < k){
                split.push_back(i);
            }
        }
        if (split.size() == 0){
            return s.size();
        }
        int result = 0;
        int left = 0;
        split.push_back(s.size());
        for (int& end : split){
            if (end - left > result){
                result = max(result, longestSubstring(s.substr(left, end - left), k));
            }
            left = end + 1;
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
