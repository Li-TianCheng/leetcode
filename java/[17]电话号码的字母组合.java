//给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。 
//
// 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。 
//
// 
//
// 示例: 
//
// 输入："23"
//输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
// 
//
// 说明: 
//尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。 
// Related Topics 字符串 回溯算法 
// 👍 825 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    Map<String, String> map = new HashMap<String, String>(){
        {
            put("2", "abc");
            put("3", "def");
            put("4", "ghi");
            put("5", "jkl");
            put("6", "mno");
            put("7", "pqrs");
            put("8", "tuv");
            put("9", "wxyz");
        }
    };
    List<String> result = new ArrayList<String>();

    public List<String> letterCombinations(String digits) {
//        if(digits.length() != 0)
//            backtrack(digits, "");
        if(digits.length() != 0){
            String sub_digit1 = digits.substring(0,1);
            String sub_digit2 = digits.substring(1);
            String letter = map.get(sub_digit1);
            for(int i=0; i < letter.length(); i++){
                result.add(letter.substring(i,i+1));
            }
            backtrack(sub_digit2);
        }
        return result;
    }

    // DFS
//    private void backtrack(String digits, String com){
//        if(digits.length() == 0){
//            result.add(com);
//            return;
//        }
//        String sub_digit1 = digits.substring(0,1);
//        String sub_digit2 = digits.substring(1);
//        String letter = map.get(sub_digit1);
//        for(int i=0; i < letter.length(); i++){
//            String temp = letter.substring(i,i+1);
//            backtrack(sub_digit2, com+temp);
//        }
//    }

    // BFS
    private void backtrack(String digits){
        if(digits.length() == 0)
            return;
        String sub_digit1 = digits.substring(0,1);
        String sub_digit2 = digits.substring(1);
        String letter = map.get(sub_digit1);
        List<String> tem_re = new ArrayList<String>();
        for(int i=0; i < letter.length(); i++){
            String temp = letter.substring(i,i+1);
            for(int j=0; j < result.size(); j++){
                tem_re.add(result.get(j)+temp);
            }
        }
        result = tem_re;
        backtrack(sub_digit2);
    }
}
//leetcode submit region end(Prohibit modification and deletion)
