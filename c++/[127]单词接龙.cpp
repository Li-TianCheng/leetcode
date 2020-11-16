//给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord 的最短转换序列的长度。转换需遵循如下规则：
// 
//
// 
// 每次转换只能改变一个字母。 
// 转换过程中的中间单词必须是字典中的单词。 
// 
//
// 说明: 
//
// 
// 如果不存在这样的转换序列，返回 0。 
// 所有单词具有相同的长度。 
// 所有单词只由小写字母组成。 
// 字典中不存在重复的单词。 
// 你可以假设 beginWord 和 endWord 是非空的，且二者不相同。 
// 
//
// 示例 1: 
//
// 输入:
//beginWord = "hit",
//endWord = "cog",
//wordList = ["hot","dot","dog","lot","log","cog"]
//
//输出: 5
//
//解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
//     返回它的长度 5。
// 
//
// 示例 2: 
//
// 输入:
//beginWord = "hit"
//endWord = "cog"
//wordList = ["hot","dot","dog","lot","log"]
//
//输出: 0
//
//解释: endWord "cog" 不在字典中，所以无法进行转换。 
// Related Topics 广度优先搜索 
// 👍 639 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    unordered_map<string, list<string>> graph;
    unordered_set<string> dict;

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int result = 0;
        queue<string> queue;
        unordered_set<string> visited;
        for (string word : wordList) {
            dict.insert(word);
        }
        addGraph(beginWord);
        for (string word : wordList) {
            addGraph(word);
        }
        addGraph(endWord);
        if (graph.find(endWord) == graph.end()){
            return result;
        }
        queue.push(beginWord);
        visited.insert(beginWord);
        while (!queue.empty()){
            int size = queue.size();
            result++;
            for (int i = 0; i < size; i++){
                string node = queue.front();
                queue.pop();
                list<string> edges = graph[node];
                for (string edge : edges){
                    if (visited.find(edge) == visited.end()){
                        if (edge == endWord){
                            return result + 1;
                        }
                        queue.push(edge);
                        visited.insert(edge);
                    }
                }
            }
        }
        return 0;
    }

    void addGraph(string word){
        if (graph.find(word) == graph.end()){
            graph[word] = getEdges(word);
        }
    }

    list<string> getEdges(string word){
        list<string> result;
        string chs = word;
        for (char ch = 'a'; ch <= 'z'; ch++) {
            for (int i = 0; i < word.size(); i++) {
                if (word[i] == ch){
                    continue;
                }
                char oldCh = word[i];
                chs[i] = ch;
                if (dict.find(chs) != dict.end()) {
                    result.push_back(chs);
                }
                chs[i] = oldCh;
            }
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
