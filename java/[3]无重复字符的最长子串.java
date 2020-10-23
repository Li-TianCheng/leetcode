//给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。 
//
// 示例 1: 
//
// 输入: "abcabcbb"
//输出: 3 
//解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
// 
//
// 示例 2: 
//
// 输入: "bbbbb"
//输出: 1
//解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
// 
//
// 示例 3: 
//
// 输入: "pwwkew"
//输出: 3
//解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
//     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
// 
// Related Topics 哈希表 双指针 字符串 Sliding Window 
// 👍 4076 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public int lengthOfLongestSubstring(String s) {
        //method 1
//        Set<Character> hashset = new HashSet<Character>();
//        int index = -1;
//        int result = 0;
//        for(int i=0; i < s.length(); i++){
//            while (true){
//                if(index+1 < s.length()){
//                    index++;
//                }
//                if(!hashset.contains(s.charAt(index))){
//                    hashset.add(s.charAt(index));
//                    result = Math.max(index-i+1, result);
//                }else {
//                    index--;
//                    hashset.remove(s.charAt(i));
//                    break;
//                }
//            }
//        }
//        return result;

        //method 2
//        Map<Character, Integer> hashmap = new HashMap<>();
//        int index = -1;
//        int result = 0;
//        int i = 0;
//        while (true){
//            if(i+1 > s.length()){
//                break;
//            }
//            while (true){
//                if(index+1 < s.length()){
//                    index++;
//                }
//                if(!hashmap.containsKey(s.charAt(index))){
//                    hashmap.put(s.charAt(index), index);
//                    result = Math.max(index-i+1, result);
//                }else {
//                    int tempt_index = hashmap.get(s.charAt(index));
//                    index--;
//                    for(int j=i; j<tempt_index+1; j++){
//                        hashmap.remove(s.charAt(j));
//                    }
//                    i = tempt_index + 1;
//                    break;
//                }
//            }
//        }
//        return result;

        Map<Character,Integer> map=new HashMap<Character,Integer>();
        int ans=0,n=s.length();
        for(int start=0,end=0;end<n;end++){
            char temp=s.charAt(end);
            if(map.containsKey(temp)){
                start=Math.max(start,map.get(temp));
            }
            ans=Math.max(ans,end-start+1);
            map.put(s.charAt(end),end+1);
        }
        return ans;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
