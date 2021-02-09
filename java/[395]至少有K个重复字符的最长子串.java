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
    public int longestSubstring(String s, int k) {
        if (s.length() < k) {
            return 0;
        }
        HashMap<Character, Integer> map = new HashMap<>();
        List<Integer> split = new ArrayList<>();
        for (char c : s.toCharArray()){
            if (!map.containsKey(c)){
                map.put(c, 0);
            }
            map.put(c, map.get(c)+1);
        }
        for (int i = 0; i < s.length(); i++){
            if (map.get(s.charAt(i)) < k){
                split.add(i);
            }
        }
        if (split.size() == 0){
            return s.length();
        }
        split.add(s.length());
        int left = 0;
        int result = 0;
        for (int end : split){
            if (end - left > result){
                result = Math.max(result, longestSubstring(s.substring(left, end), k));
            }
            left = end + 1;
        }
        return result;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
