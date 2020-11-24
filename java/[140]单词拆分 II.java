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
    public List<String> wordBreak(String s, List<String> wordDict) {
        HashSet<String> set = new HashSet<>();
        int minSize = Integer.MAX_VALUE;
        int maxSize = Integer.MIN_VALUE;
        for (String word : wordDict) {
            minSize = Math.min(minSize, word.length());
            maxSize = Math.max(maxSize, word.length());
            set.add(word);
        }
        StringBuilder sb = new StringBuilder();
        List<String> result = new ArrayList<>();
        backtrace(s, set, sb, result, minSize, maxSize);
        return result;
    }

    private void backtrace(String s, HashSet<String> set, StringBuilder sb, List<String> result, int minSize, int maxSize) {
        if (s.length() == 0) {
            sb.deleteCharAt(sb.length() - 1);
            result.add(sb.toString());
            sb.append(" ");
            return;
        }
        for (int i = 1; i <= s.length(); i++) {
            if (!set.contains(s.substring(0, i))) {
                continue;
            }
            if (!isValid(s.substring(i), set, minSize, maxSize)){
                continue;
            }
            sb.append(s.substring(0, i)).append(" ");
            backtrace(s.substring(i), set, sb, result, minSize, maxSize);
            sb.delete(sb.length()-i-1, sb.length());
        }
    }

    private boolean isValid(String s, HashSet<String> set, int minSize, int maxSize) {
        boolean[] dp = new boolean[s.length()+1];
        dp[0] = true;
        for (int i = 1; i <= s.length(); i++) {
            for (int j = Math.max(0, i-maxSize); j <= i-minSize; j++) {
                if (dp[j] && set.contains(s.substring(j, i))){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }
}
//leetcode submit region end(Prohibit modification and deletion)
