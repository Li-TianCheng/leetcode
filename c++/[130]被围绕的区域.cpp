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
public:
    //method1
    class Union{
    public:
        vector<int> un;
        Union(int num){
            for(int i=0; i < num; i++) {
                un.push_back(i);
            }
        }

        void merge(int node1, int node2){
            int root1 = find(node1);
            int root2 = find(node2);
            if (root1 != root2){
                un[root1] = root2;
            }
        }

        int find(int node){
            if (un[node] != node){
                un[node] = find(un[node]);
            }
            return un[node];
        }
    };

    void solve(vector<vector<char>>& board) {
        if (board.size() == 0){
            return;
        }
        int m = board.size();
        int n = board[0].size();
        Union* un = new Union(m*n+1);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || i == m-1 || j == 0 || j == n-1){
                    if (board[i][j] == 'O'){
                        un->merge(i*n+j+1, 0);
                    }
                }else{
                    if (board[i][j] == 'O'){
                        if (board[i-1][j] == 'O'){
                            un->merge(i*n+j+1, (i-1)*n+j+1);
                        }
                        if (board[i+1][j] == 'O'){
                            un->merge(i*n+j+1, (i+1)*n+j+1);
                        }
                        if (board[i][j-1] == 'O'){
                            un->merge(i*n+j+1, i*n+j);
                        }
                        if (board[i][j+1] == 'O'){
                            un->merge(i*n+j+1, i*n+j+2);
                        }
                    }
                }
            }
        }
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (board[i][j] == 'O'){
                    if (un->find(i*n+j+1) != un->find(0)){
                        board[i][j] = 'X';
                    }
                }
            }
        }
    }

    // method2
//    void solve(vector<vector<char>>& board) {
//        if (board.size() == 0) {
//            return;
//        }
//        for (int i = 0; i < board[0].size(); i++) {
//            backtrack(board, 0, i);
//            backtrack(board, board.size()-1, i);
//        }
//        for (int i = 1; i < board.size()-1; i++) {
//            backtrack(board, i, 0);
//            backtrack(board, i, board[0].size()-1);
//        }
//        for (int i = 0; i < board.size(); i++) {
//            for (int j = 0; j < board[i].size(); j++){
//                if (board[i][j] == 'O'){
//                    board[i][j] = 'X';
//                }
//                if (board[i][j] == '#'){
//                    board[i][j] = 'O';
//                }
//            }
//        }
//    }
//
//    void backtrack(vector<vector<char>>& board, int x, int y) {
//        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] != 'O'){
//            return;
//        }
//        board[x][y] = '#';
//        backtrack(board, x-1, y);
//        backtrack(board, x+1, y);
//        backtrack(board, x, y-1);
//        backtrack(board, x, y+1);
//    }
};
//leetcode submit region end(Prohibit modification and deletion)
