//给你一个字符串 S、一个字符串 T 。请你设计一种算法，可以在 O(n) 的时间复杂度内，从字符串 S 里面找出：包含 T 所有字符的最小子串。 
//
// 
//
// 示例： 
//
// 输入：S = "ADOBECODEBANC", T = "ABC"
//输出："BANC" 
//
// 
//
// 提示： 
//
// 
// 如果 S 中不存这样的子串，则返回空字符串 ""。 
// 如果 S 中存在这样的子串，我们保证它是唯一的答案。 
// 
// Related Topics 哈希表 双指针 字符串 Sliding Window 
// 👍 795 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string minWindow(string s, string t) {
        int start = 0;
        int end = INT32_MAX;
        int temStart = 0;
        int n = t.size();
        unordered_map<char, int> map;
        for (char c : t) {
            if (map.find(c) == map.end())
                map[c] = 1;
            else
                map[c]++;
        }
        for (; temStart < s.size(); temStart++) {
            if (map.find(s[temStart]) != map.end())
                break;
        }
        int temEnd = temStart;
        while (temEnd < s.size() && temStart < s.size()){
            if (temEnd < temStart)
                temEnd = temStart;
            if (map.find(s[temEnd]) != map.end()){
                map[s[temEnd]]--;
                if (map[s[temEnd]] >= 0)
                    n--;
            }
            while (n == 0 && temStart < s.size()){
                if (temEnd - temStart < end - start){
                    start = temStart;
                    end = temEnd;
                }
                map[s[temStart]]++;
                if (map[s[temStart]] > 0)
                    n++;
                temStart++;
                for (; temStart < s.size(); temStart++){
                    if (map.find(s[temStart]) != map.end())
                        break;
                }
            }
            temEnd++;
        }
        return end == INT32_MAX ? "" : s.substr(start, end-start+1);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
