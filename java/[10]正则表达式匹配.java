//给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。 
//
// '.' 匹配任意单个字符
//'*' 匹配零个或多个前面的那一个元素
// 
//
// 所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。 
//
// 说明: 
//
// 
// s 可能为空，且只包含从 a-z 的小写字母。 
// p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。 
// 
//
// 示例 1: 
//
// 输入:
//s = "aa"
//p = "a"
//输出: false
//解释: "a" 无法匹配 "aa" 整个字符串。
// 
//
// 示例 2: 
//
// 输入:
//s = "aa"
//p = "a*"
//输出: true
//解释: 因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
// 
//
// 示例 3: 
//
// 输入:
//s = "ab"
//p = ".*"
//输出: true
//解释: ".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
// 
//
// 示例 4: 
//
// 输入:
//s = "aab"
//p = "c*a*b"
//输出: true
//解释: 因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。
// 
//
// 示例 5: 
//
// 输入:
//s = "mississippi"
//p = "mis*is*p*."
//输出: false 
// Related Topics 字符串 动态规划 回溯算法 
// 👍 1430 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public boolean isMatch(String s, String p) {
        //method1
        int length_s = s.length();
        int length_p = p.length();
        boolean[][] match_result = new boolean[length_s+1][length_p+1];
        match_result[0][0] = true;
        for(int j=1; j < length_p + 1; j++){
            if(p.charAt(j-1) != '*')
                match_result[0][j] = false;
            else
                match_result[0][j] = match_result[0][j-2];
        }
        for (int i=1; i < length_s + 1; i++){
            for (int j=1; j < length_p + 1; j++){
                if(p.charAt(j-1) != '*'){
                    if(Match(s.charAt(i-1), p.charAt(j-1)))
                        match_result[i][j] = match_result[i-1][j-1];
                    else
                        match_result[i][j] = false;
                }else {
                    if(Match(s.charAt(i-1), p.charAt(j-2)))
                        match_result[i][j] = match_result[i-1][j] || match_result[i][j-2];
                    else
                        match_result[i][j] = match_result[i][j-2];
                }
            }
        }
        return match_result[length_s][length_p];
        //method2
//        Automaton automaton = new Automaton();
//        Node state = automaton.GenerateSate(p);
//        if(s.length() == 0){
//            while (state != null){
//                if(state.isStar)
//                    state = state.next;
//                else
//                    return false;
//            }
//        }
//        for(int i=0; i < s.length(); i++){
//            if(state == null)
//                return false;
//            if(state.end)
//                return false;
//            state = automaton.State_translate(state, s.charAt(i));
//        }
//        if(state == null)
//            return true;
//        else{
//            if (state.isStar)
//                return state.next == null;
//            else
//                return false;
//        }
    }

    private boolean Match(char s, char p){
        if(p == '.')
            return true;
        return s == p;
    }
}

//class Node{
//    public char c;
//    public boolean isStar = false;
//    public Node next = null;
//    public boolean end = false;
//}
//
//class Automaton{
//    public Node GenerateSate(String p){
//        Node root = new Node();
//        Node curr = root;
//        int i = 0;
//        while (i < p.length()){
//            if(i+1 >= p.length()){
//                Node temp = new Node();
//                temp.c = p.charAt(i);
//                curr.next = temp;
//                break;
//            }
//            if(p.charAt(i+1) != '*'){
//                Node temp = new Node();
//                temp.c = p.charAt(i);
//                curr.next = temp;
//                curr = temp;
//                i++;
//            }else {
//                Node temp = new Node();
//                temp.c = p.charAt(i);
//                temp.isStar = true;
//                curr.next = temp;
//                curr = temp;
//                i = i + 2;
//            }
//        }
//        return root.next;
//    }
//
//    public Node State_translate(Node state, char c){
//        if(state.isStar){
//            if(Match(c, state.c))
//                return state;
//            else
//            if(state.next == null){
//                state.end = true;
//                return state;
//            }else
//                return State_translate(state.next, c);
//        }else {
//            if(Match(c, state.c))
//                return state.next;
//            else{
//                state.end = true;
//                return state;
//            }
//        }
//    }
//
//    public boolean Match(char s, char p){
//        if(p == '.')
//            return true;
//        else
//            return p == s;
//    }
//}

//leetcode submit region end(Prohibit modification and deletion)
