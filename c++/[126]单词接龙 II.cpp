//给定两个单词（beginWord 和 endWord）和一个字典 wordList，找出所有从 beginWord 到 endWord 的最短转换序列。转换
//需遵循如下规则： 
//
// 
// 每次转换只能改变一个字母。 
// 转换后得到的单词必须是字典中的单词。 
// 
//
// 说明: 
//
// 
// 如果不存在这样的转换序列，返回一个空列表。 
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
//输出:
//[
//  ["hit","hot","dot","dog","cog"],
//  ["hit","hot","lot","log","cog"]
//]
// 
//
// 示例 2: 
//
// 输入:
//beginWord = "hit"
//endWord = "cog"
//wordList = ["hot","dot","dog","lot","log"]
//
//输出: []
//
//解释: endWord "cog" 不在字典中，所以不存在符合要求的转换序列。 
// Related Topics 广度优先搜索 数组 字符串 回溯算法 
// 👍 358 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> result;
        BFS(beginWord, endWord, wordList, result);
        return result;
    }

    void BFS(string beginWord, string endWord, vector<string>& wordList, vector<vector<string>>& result){
        queue<vector<string>> queue;
        vector<string> path;
        path.push_back(beginWord);
        queue.push(path);
        bool isFound = false;
        unordered_set<string> dict;
        unordered_set<string> visited;
        for (string word : wordList){
            dict.insert(word);
        }
        visited.insert(beginWord);
        while (!queue.empty()){
            int size = queue.size();
            unordered_set<string> subVisited;
            for (int i = 0; i < size; i++){
                vector<string> p = queue.front();
                queue.pop();
                string curr = p.back();
                list<string> neighbors = getNeighbors(curr, dict);
                for (string neighbor : neighbors){
                    if (visited.find(neighbor) == visited.end()){
                        if (neighbor == endWord){
                            isFound = true;
                            p.push_back(neighbor);
                            result.push_back(p);
                            p.pop_back();
                        }
                        p.push_back(neighbor);
                        queue.push(p);
                        p.pop_back();
                        subVisited.insert(neighbor);
                    }
                }
            }
            for (string s : subVisited){
                visited.insert(s);
            }
            if (isFound){
                break;
            }
        }
    }

    list<string> getNeighbors(string curr, unordered_set<string> dict){
        list<string> result;
        string chs = curr;
        for (char ch = 'a'; ch <= 'z'; ch++) {
            for (int i = 0; i < curr.size(); i++) {
                if (curr[i] == ch){
                    continue;
                }
                char oldCh = curr[i];
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
