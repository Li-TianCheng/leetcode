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
    public String removeDuplicateLetters(String s) {
        Deque<Character> queue = new ArrayDeque<>();
        HashMap<Character, Integer> map = new HashMap<>();
        for (char c : s.toCharArray()){
            if (!map.containsKey(c)){
                map.put(c, 1);
            }else{
                map.put(c, map.get(c)+1);
            }
        }
        for (char c : s.toCharArray()){
            if (queue.isEmpty()){
                queue.offerLast(c);
            }else {
                if (queue.contains(c)){
                    map.put(c, map.get(c)-1);
                    continue;
                }
                while (!queue.isEmpty()){
                    char curr = queue.getLast();
                    if (c < curr && map.get(curr) > 1){
                        queue.pollLast();
                        map.put(curr, map.get(curr)-1);
                    }else{
                        break;
                    }
                }
                queue.offerLast(c);
            }
        }
        StringBuilder sb = new StringBuilder();
        while (!queue.isEmpty()){
            sb.append(queue.pollFirst());
        }
        return sb.toString();
    }
}
//leetcode submit region end(Prohibit modification and deletion)
