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
    public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
        List<List<String>> result = new ArrayList<>();
        BFS(beginWord, endWord, wordList, result);
        return result;
    }

    private void BFS(String beginWord, String endWord, List<String> wordList, List<List<String>> result){
        Queue<List<String>> queue = new LinkedList<>();
        List<String> path = new ArrayList<>();
        path.add(beginWord);
        queue.add(path);
        boolean isFound = false;
        Set<String> dict = new HashSet<>(wordList);
        Set<String> visited = new HashSet<>();
        visited.add(beginWord);
        while (!queue.isEmpty()){
            int size = queue.size();
            Set<String> subVisited = new HashSet<>();
            for (int i = 0; i < size; i++){
                List<String> p = queue.poll();
                String curr = p.get(p.size() - 1);
                List<String> neighbors = getNeighbors(curr, dict);
                for (String neighbor : neighbors){
                    if (!visited.contains(neighbor)){
                        if (neighbor.equals(endWord)){
                            isFound = true;
                            p.add(neighbor);
                            result.add(new ArrayList<>(p));
                            p.remove(p.size() - 1);
                        }
                        p.add(neighbor);
                        queue.add(new ArrayList<>(p));
                        p.remove(p.size() - 1);
                        subVisited.add(neighbor);
                    }
                }
            }
            visited.addAll(subVisited);
            if (isFound){
                break;
            }
        }
    }

    private List<String> getNeighbors(String curr, Set<String> dict) {
        List<String> result = new ArrayList<>();
        char[] chs = curr.toCharArray();
        for (char ch = 'a'; ch <= 'z'; ch++) {
            for (int i = 0; i < chs.length; i++) {
                if (chs[i] == ch){
                    continue;
                }
                char oldCh = chs[i];
                chs[i] = ch;
                if (dict.contains(String.valueOf(chs))) {
                    result.add(String.valueOf(chs));
                }
                chs[i] = oldCh;
            }
        }
        return result;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
