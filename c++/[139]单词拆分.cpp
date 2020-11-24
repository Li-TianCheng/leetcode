//给定一个非空字符串 s 和一个包含非空单词的列表 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。 
//
// 说明： 
//
// 
// 拆分时可以重复使用字典中的单词。 
// 你可以假设字典中没有重复的单词。 
// 
//
// 示例 1： 
//
// 输入: s = "leetcode", wordDict = ["leet", "code"]
//输出: true
//解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
// 
//
// 示例 2： 
//
// 输入: s = "applepenapple", wordDict = ["apple", "pen"]
//输出: true
//解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
//     注意你可以重复使用字典中的单词。
// 
//
// 示例 3： 
//
// 输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
//输出: false
// 
// Related Topics 动态规划 
// 👍 759 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (wordDict.size() == 0){
            return false;
        }
        unordered_set<string> set;
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        int minSize = INT32_MAX;
        int maxSize = INT32_MIN;
        for (string word : wordDict){
            set.insert(word);
            minSize = min(minSize, (int)word.size());
            maxSize = max(maxSize, (int)word.size());
        }
        for (int i = 1; i <= s.size(); i++) {
            for (int j = max(0, i-maxSize); j <= i-minSize; j++) {
                if (dp[j] && set.find(s.substr(j, i-j)) != set.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
