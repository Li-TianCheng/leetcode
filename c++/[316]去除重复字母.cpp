//给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次。需保证 返回结果的字典序最小（要求不能打乱其他字符的相对位置）。 
//
// 注意：该题与 1081 https://leetcode-cn.com/problems/smallest-subsequence-of-distinct
//-characters 相同 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "bcabc"
//输出："abc"
// 
//
// 示例 2： 
//
// 
//输入：s = "cbacdcbc"
//输出："acdb" 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 104 
// s 由小写英文字母组成 
// 
// Related Topics 栈 贪心算法 字符串 
// 👍 297 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string removeDuplicateLetters(string s) {
        string result;
        unordered_map<char, int> map;
        for (char c : s) {
            if (map.find(c) == map.end()){
                map[c] = 1;
            }else {
                map[c]++;
            }
        }

        for (char c : s) {
            if (result.empty()){
                result += c;
            }else {
                if (result.find(c) != string::npos){
                    map[c]--;
                    continue;
                }
                while (!result.empty()){
                    char curr = result.back();
                    if (c < curr && map[curr] > 1){
                        result.pop_back();
                        map[curr]--;
                    }else {
                        break;
                    }
                }
                result+=c;
            }
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
