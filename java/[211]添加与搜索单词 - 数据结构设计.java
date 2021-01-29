//请你设计一个数据结构，支持 添加新单词 和 查找字符串是否与任何先前添加的字符串匹配 。 
//
// 实现词典类 WordDictionary ： 
//
// 
// WordDictionary() 初始化词典对象 
// void addWord(word) 将 word 添加到数据结构中，之后可以对它进行匹配 
// bool search(word) 如果数据结构中存在字符串与 word 匹配，则返回 true ；否则，返回 false 。word 中可能包含一些 '
//.' ，每个 . 都可以表示任何一个字母。 
// 
//
// 
//
// 示例： 
//
// 
//输入：
//["WordDictionary","addWord","addWord","addWord","search","search","search","se
//arch"]
//[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
//输出：
//[null,null,null,null,false,true,true,true]
//
//解释：
//WordDictionary wordDictionary = new WordDictionary();
//wordDictionary.addWord("bad");
//wordDictionary.addWord("dad");
//wordDictionary.addWord("mad");
//wordDictionary.search("pad"); // return False
//wordDictionary.search("bad"); // return True
//wordDictionary.search(".ad"); // return True
//wordDictionary.search("b.."); // return True
// 
//
// 
//
// 提示： 
//
// 
// 1 <= word.length <= 500 
// addWord 中的 word 由小写英文字母组成 
// search 中的 word 由 '.' 或小写英文字母组成 
// 最调用多 50000 次 addWord 和 search 
// 
// Related Topics 深度优先搜索 设计 字典树 回溯算法 
// 👍 202 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class WordDictionary {
    private class Node{
        boolean isEnd = false;
        Node[] children = new Node[26];
    }
    Node root = null;

    /** Initialize your data structure here. */
    public WordDictionary() {
        root = new Node();
    }

    public void addWord(String word) {
        Node curr = root;
        for (char c : word.toCharArray()){
            c -= 'a';
            if (curr.children[c] == null){
                curr.children[c] = new Node();
            }
            curr = curr.children[c];
        }
        curr.isEnd = true;
    }

    public boolean search(String word) {
        Node curr = root;
        return searchHelp(curr, word);
    }

    public boolean searchHelp(Node curr, String subWord){
        for (int i = 0; i < subWord.length(); i++){
            char c = subWord.charAt(i);
            if (c != '.'){
                c -= 'a';
                if (curr.children[c] == null){
                    return false;
                }
                curr = curr.children[c];
            }else{
                for (Node n : curr.children){
                    if (n != null){
                        if (searchHelp(n, subWord.substring(i+1))){
                            return true;
                        }
                    }
                }
                return false;
            }
        }
        return curr.isEnd;
    }
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */
//leetcode submit region end(Prohibit modification and deletion)
