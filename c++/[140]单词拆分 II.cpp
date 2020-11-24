//给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，在字符串中增加空格来构建一个句子，使得句子中所有的单词都在词典中。返回所有这些可能的
//句子。 
//
// 说明： 
//
// 
// 分隔时可以重复使用字典中的单词。 
// 你可以假设字典中没有重复的单词。 
// 
//
// 示例 1： 
//
// 输入:
//s = "catsanddog"
//wordDict = ["cat", "cats", "and", "sand", "dog"]
//输出:
//[
//  "cats and dog",
//  "cat sand dog"
//]
// 
//
// 示例 2： 
//
// 输入:
//s = "pineapplepenapple"
//wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
//输出:
//[
//  "pine apple pen apple",
//  "pineapple pen apple",
//  "pine applepen apple"
//]
//解释: 注意你可以重复使用字典中的单词。
// 
//
// 示例 3： 
//
// 输入:
//s = "catsandog"
//wordDict = ["cats", "dog", "sand", "and", "cat"]
//输出:
//[]
// 
// Related Topics 动态规划 回溯算法 
// 👍 370 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set;
        int minSize = INT32_MAX;
        int maxSize = INT32_MIN;
        for (string word : wordDict){
            minSize = min(minSize, (int)word.size());
            maxSize = max(maxSize, (int)word.size());
            set.insert(word);
        }
        string temp;
        vector<string> result;
        backtrack(s, set, temp, result, minSize, maxSize);
        return  result;
    }

    void backtrack(string s, unordered_set<string>& set, string temp, vector<string>& result, int& minSize, int& maxSize){
        if (s.size() == 0){
            temp.erase(temp.size()-1);
            result.push_back(temp);
            temp += ' ';
        }
        for (int i = 1; i <= s.size(); i++){
            if (set.find(s.substr(0, i)) == set.end()){
                continue;
            }
            if (!isValid(s.substr(i), set, minSize, maxSize)){
                continue;
            }
            temp += s.substr(0, i);
            temp += ' ';
            backtrack(s.substr(i), set, temp, result, minSize, maxSize);
            temp.erase(temp.size()-i-1, i+1);
        }
    }

    bool isValid(string s, unordered_set<string>& set, int& minSize, int& maxSize){
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
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
