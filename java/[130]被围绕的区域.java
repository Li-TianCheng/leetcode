//给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。 
//
// 找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。 
//
// 示例: 
//
// X X X X
//X O O X
//X X O X
//X O X X
// 
//
// 运行你的函数后，矩阵变为： 
//
// X X X X
//X X X X
//X X X X
//X O X X
// 
//
// 解释: 
//
// 被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被
//填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。 
// Related Topics 深度优先搜索 广度优先搜索 并查集 
// 👍 422 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    // method1
//    private class Union{
//        public final int[] union;
//        public Union(int number){
//            union = new int[number];
//            for (int i = 0; i < number; i++){
//                union[i] = i;
//            }
//        }
//
//        public void merge(int node1, int node2){
//            int root1 = find(node1);
//            int root2 = find(node2);
//            if (root1 != root2){
//                union[root1] = root2;
//            }
//        }
//
//        public int find(int node){
//            if (union[node] != node){
//                union[node] = find(union[node]);
//            }
//            return union[node];
//        }
//    }
//    public void solve(char[][] board) {
//        if (board.length == 0){
//            return;
//        }
//        int m = board.length;
//        int n = board[0].length;
//        Union union = new Union(m * n + 1);
//        for (int i = 0; i < m; i++){
//            for (int j = 0; j < n; j++){
//                if (i == 0 || i == m-1 || j == 0 || j == n-1){
//                    if (board[i][j] == 'O'){
//                        union.merge(i*n+j+1, 0);
//                    }
//                }else {
//                    if (board[i][j] == 'O'){
//                        if (board[i-1][j] == 'O'){
//                            union.merge(i*n+j+1, (i-1)*n+j+1);
//                        }
//                        if (board[i+1][j] == 'O'){
//                            union.merge(i*n+j+1, (i+1)*n+j+1);
//                        }
//                        if (board[i][j-1] == 'O'){
//                            union.merge(i*n+j+1, i*n+j);
//                        }
//                        if (board[i][j+1] == 'O'){
//                            union.merge(i*n+j+1, i*n+j+2);
//                        }
//                    }
//                }
//            }
//        }
//        for (int i = 0; i < m; i++){
//            for (int j = 0; j < n; j++){
//                if (board[i][j] == 'O'){
//                    if (union.find(i*n+j+1) != union.find(0)){
//                        board[i][j] = 'X';
//                    }
//                }
//            }
//        }
//    }

    // method2
    public void solve(char[][] board) {
        if (board.length == 0){
            return;
        }
        for (int i = 0; i < board[0].length; i++){
            backtrace(board, 0, i);
            backtrace(board, board.length-1, i);
        }
        for (int i = 1; i < board.length-1; i++){
            backtrace(board, i, 0);
            backtrace(board, i, board[0].length-1);
        }
        for (int i = 0; i < board.length; i++){
            for (int j = 0; j < board[0].length; j++){
                if (board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                if (board[i][j] == '#'){
                    board[i][j] = 'O';
                }
            }
        }
    }

    private void backtrace(char[][] board, int x, int y){
        if (x < 0 || x >= board.length || y < 0 || y >= board[0].length || board[x][y] != 'O'){
            return;
        }
        board[x][y] = '#';
        backtrace(board, x-1, y);
        backtrace(board, x+1, y);
        backtrace(board, x, y-1);
        backtrace(board, x, y+1);
    }
}
//leetcode submit region end(Prohibit modification and deletion)
