//给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。 
//
// 返回 s 所有可能的分割方案。 
//
// 示例: 
//
// 输入: "aab"
//输出:
//[
//  ["aa","b"],
//  ["a","a","b"]
//] 
// Related Topics 回溯算法 
// 👍 424 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public List<List<String>> partition(String s) {
        List<List<String>> result = new ArrayList<>();
        List<String> temp = new ArrayList<>();
        backtrace(s, result, temp);
        return result;
    }

    private void backtrace(String s, List<List<String>> result, List<String> temp){
        if (s.length() == 0){
            result.add(new ArrayList<>(temp));
            return;
        }
        for (int i = 1; i <= s.length(); i++){
            if (!isValid(s.substring(0, i))){
                continue;
            }
            temp.add(s.substring(0, i));
            backtrace(s.substring(i), result, temp);
            temp.remove(temp.size() - 1);
        }
    }

    private boolean isValid(String s){
        int left = 0;
        int right = s.length() - 1;
        while (left < right) {
            if (s.charAt(left) != s.charAt(right)){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
