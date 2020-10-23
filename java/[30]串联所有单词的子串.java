//给定一个字符串 s 和一些长度相同的单词 words。找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置。 
//
// 注意子串要与 words 中的单词完全匹配，中间不能有其他字符，但不需要考虑 words 中单词串联的顺序。 
//
// 
//
// 示例 1： 
//
// 输入：
//  s = "barfoothefoobarman",
//  words = ["foo","bar"]
//输出：[0,9]
//解释：
//从索引 0 和 9 开始的子串分别是 "barfoo" 和 "foobar" 。
//输出的顺序不重要, [9,0] 也是有效答案。
// 
//
// 示例 2： 
//
// 输入：
//  s = "wordgoodgoodgoodbestword",
//  words = ["word","good","best","word"]
//输出：[]
// 
// Related Topics 哈希表 双指针 字符串 
// 👍 320 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        List<Integer> result = new ArrayList<>();
        int wordnum = words.length;
        if(wordnum == 0)
            return result;
        int wordlen = words[0].length();
        HashMap<String, Integer> map1 = new HashMap<>();
        for(String w : words){
            int value = map1.getOrDefault(w, 0);
            map1.put(w, value + 1);
        }
        for(int i = 0; i < s.length() - wordnum * wordlen + 1; i++){
            HashMap<String, Integer> map2 = new HashMap<>();
            boolean flag = true;
            for(int j = 0; j < wordnum; j++){
                String sub = s.substring(i + j * wordlen, i + (j + 1) * wordlen);
                if(map1.containsKey(sub)){
                    int sub_value = map2.getOrDefault(sub, 0);
                    if(sub_value < map1.get(sub))
                        map2.put(sub, sub_value + 1);
                    else{
                        flag = false;
                        break;
                    }
                }else {
                    flag = false;
                    break;
                }
            }
            if(flag)
                result.add(i);
        }
        return result;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
