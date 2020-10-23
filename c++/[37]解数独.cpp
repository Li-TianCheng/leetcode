//编写一个程序，通过填充空格来解决数独问题。 
//
// 一个数独的解法需遵循如下规则： 
//
// 
// 数字 1-9 在每一行只能出现一次。 
// 数字 1-9 在每一列只能出现一次。 
// 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。 
// 
//
// 空白格用 '.' 表示。 
//
// 
//
// 一个数独。 
//
// 
//
// 答案被标成红色。 
//
// 提示： 
//
// 
// 给定的数独序列只包含数字 1-9 和字符 '.' 。 
// 你可以假设给定的数独只有唯一解。 
// 给定数独永远是 9x9 形式的。 
// 
// Related Topics 哈希表 回溯算法 
// 👍 654 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool rows[9][10] ={false};
    bool columns[9][10] ={false};
    bool boxes[9][10] ={false};
    bool sudokuSolved = false;
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char num = board[i][j];
                if (num != '.')
                    placeNumber(board, num-'0', i, j);
            }
        }
        backtrack(board, 0, 0);
    }

    bool couldPlace(const int& d, const int& row, const int& col) {
        int idx = (row/3)*3 + col/3;
        return !(rows[row][d] | columns[col][d] | boxes[idx][d]);
    }

    void placeNumber(vector<vector<char>>& board, const int& d, const int& row, const int& col) {
        int idx = (row/3)*3 + col/3;
        rows[row][d] = true;
        columns[col][d] = true;
        boxes[idx][d] = true;
        board[row][col] = (char)(d + '0');
    }

    void removeNumber(vector<vector<char>>& board, const int& d, const int& row, const int& col){
        int idx = (row/3)*3 + col/3;
        rows[row][d] = false;
        columns[col][d] = false;
        boxes[idx][d] = false;
        board[row][col] = '.';
    }

    void placeNextNumber(vector<vector<char>>& board, const int& row, const int& col) {
        if (row == 8 && col == 8)
            sudokuSolved = true;
        else {
            if (col == 8)
                backtrack(board, row+1, 0);
            else
                backtrack(board, row, col+1);
        }
    }

    void backtrack(vector<vector<char>>& board, const int& row, const int& col){
        if (board[row][col] == '.') {
            for (int d = 1; d < 10; d++){
                if (couldPlace(d, row, col)){
                    placeNumber(board, d, row, col);
                    placeNextNumber(board, row, col);
                    if (!sudokuSolved)
                        removeNumber(board, d, row, col);
                }
            }
        }else
            placeNextNumber(board, row, col);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
