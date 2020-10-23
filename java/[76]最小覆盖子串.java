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
// 👍 784 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public String minWindow(String s, String t) {
        int start = 0;
        int end = Integer.MAX_VALUE;
        int temStart = 0;
        int n = t.length();
        HashMap<Character, Integer> map = new HashMap<>();
        for (char c : t.toCharArray()){
            if (!map.containsKey(c))
                map.put(c, 1);
            else
                map.put(c, map.get(c)+1);
        }
        for (; temStart < s.length(); temStart++)
            if (map.containsKey(s.charAt(temStart)))
                break;
        int temEnd = temStart;
        while (temEnd < s.length() && temStart < s.length()){
            if (temEnd < temStart)
                temEnd = temStart;
            if (map.containsKey(s.charAt(temEnd))){
                map.put(s.charAt(temEnd), map.get(s.charAt(temEnd))-1);
                if (map.get(s.charAt(temEnd)) >= 0)
                    n--;
            }
            while (n == 0 && temStart < s.length()){
                if (temEnd - temStart < end - start){
                    start = temStart;
                    end = temEnd;
                }
                map.put(s.charAt(temStart), map.get(s.charAt(temStart))+1);
                if (map.get(s.charAt(temStart)) > 0)
                    n++;
                temStart++;
                for (; temStart < s.length(); temStart++){
                    if (map.containsKey(s.charAt(temStart))){
                        break;
                    }
                }
            }
            temEnd++;
        }
        return end == Integer.MAX_VALUE ? "" : s.substring(start, end+1);
    }
}
//leetcode submit region end(Prohibit modification and deletion)
