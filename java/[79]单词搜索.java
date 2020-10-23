//给定一个二维网格和一个单词，找出该单词是否存在于网格中。 
//
// 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。 
//
// 
//
// 示例: 
//
// board =
//[
//  ['A','B','C','E'],
//  ['S','F','C','S'],
//  ['A','D','E','E']
//]
//
//给定 word = "ABCCED", 返回 true
//给定 word = "SEE", 返回 true
//给定 word = "ABCB", 返回 false 
//
// 
//
// 提示： 
//
// 
// board 和 word 中只包含大写和小写英文字母。 
// 1 <= board.length <= 200 
// 1 <= board[i].length <= 200 
// 1 <= word.length <= 10^3 
// 
// Related Topics 数组 回溯算法 
// 👍 651 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public boolean exist(char[][] board, String word) {
        boolean[][] visited = new boolean[board.length][board[0].length];
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (backtrace(board, word, visited, i, j, 0))
                    return true;
            }
        }
        return false;
    }

    private boolean backtrace(char[][] board, String word, boolean[][] visited, int row, int col, int k){
        if (board[row][col] == word.charAt(k)){
            if (k+1 == word.length()){
                return true;
            }
            visited[row][col] = true;
            if (row-1 >= 0)
                if (!visited[row-1][col])
                    if (backtrace(board, word, visited, row-1, col, k+1))
                        return true;
            if (row+1 < board.length)
                if (!visited[row+1][col])
                    if (backtrace(board, word, visited, row+1, col, k+1))
                        return true;
            if (col-1 >= 0)
                if (!visited[row][col-1])
                    if (backtrace(board, word, visited, row, col-1, k+1))
                        return true;
            if (col+1 < board[0].length)
                if (!visited[row][col+1])
                    if (backtrace(board, word, visited, row, col+1, k+1))
                        return true;
            visited[row][col] = false;
        }
        return false;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
