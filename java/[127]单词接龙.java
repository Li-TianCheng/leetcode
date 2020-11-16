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
// 👍 638 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    //method1
//    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
//        return BFS(beginWord, endWord, wordList);
//    }
//
//    private int BFS(String beginWord, String endWord, List<String> wordList){
//        int result = 0;
//        Queue<String> queue = new LinkedList<>();
//        queue.add(beginWord);
//        Set<String> dict = new HashSet<>(wordList);
//        Set<String> visited = new HashSet<>();
//        visited.add(beginWord);
//        while (!queue.isEmpty()){
//            result++;
//            int size = queue.size();
//            Set<String> subVisited = new HashSet<>();
//            for (int i = 0; i < size; i++){
//                String curr = queue.poll();
//                List<String> neighbors = getNeighbors(curr, dict);
//                for (String neighbor : neighbors){
//                    if (!visited.contains(neighbor)){
//                        if (neighbor.equals(endWord)){
//                            return result + 1;
//                        }
//                        queue.add(neighbor);
//                        subVisited.add(neighbor);
//                    }
//                }
//            }
//            visited.addAll(subVisited);
//        }
//        return 0;
//    }
//
//    private List<String> getNeighbors(String curr, Set<String> dict) {
//        List<String> result = new ArrayList<>();
//        char[] chs = curr.toCharArray();
//        for (char ch = 'a'; ch <= 'z'; ch++) {
//            for (int i = 0; i < chs.length; i++) {
//                if (chs[i] == ch){
//                    continue;
//                }
//                char oldCh = chs[i];
//                chs[i] = ch;
//                if (dict.contains(String.valueOf(chs))) {
//                    result.add(String.valueOf(chs));
//                }
//                chs[i] = oldCh;
//            }
//        }
//        return result;
//    }

    //method2
    HashMap<String, List<String>> graph = new HashMap<>();
    Set<String> dict;

    public int ladderLength(String beginWord, String endWord, List<String> wordList){
        int result = 0;
        Queue<String> queue = new LinkedList<>();
        HashSet<String> visited = new HashSet<>();
        dict = new HashSet<>(wordList);
        addGraph(beginWord);
        for (String word : wordList){
            addGraph(word);
        }
        addGraph(endWord);
        if (graph.get(endWord) == null){
            return result;
        }
        queue.add(beginWord);
        visited.add(beginWord);
        while (!queue.isEmpty()){
            int size = queue.size();
            result++;
            for (int i = 0; i < size; i++){
                String node = queue.poll();
                List<String> edges = graph.get(node);
                for (String edge : edges){
                    if (!visited.contains(edge)){
                        if (edge.equals(endWord)){
                            return result + 1;
                        }
                        queue.add(edge);
                        visited.add(edge);
                    }
                }
            }
        }
        return 0;
    }

    private void addGraph(String word){
        if (!graph.containsKey(word)){
            graph.put(word, getEdges(word));
        }
    }

    private List<String> getEdges(String word) {
        List<String> result = new ArrayList<>();
        char[] chs = word.toCharArray();
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
