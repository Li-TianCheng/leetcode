//n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。 
//
// 
//
// 上图为 8 皇后问题的一种解法。 
//
// 给定一个整数 n，返回 n 皇后不同的解决方案的数量。 
//
// 示例: 
//
// 输入: 4
//输出: 2
//解释: 4 皇后问题存在如下两个不同的解法。
//[
// [".Q..",  // 解法 1
//  "...Q",
//  "Q...",
//  "..Q."],
//
// ["..Q.",  // 解法 2
//  "Q...",
//  "...Q",
//  ".Q.."]
//]
// 
//
// 
//
// 提示： 
//
// 
// 皇后，是国际象棋中的棋子，意味着国王的妻子。皇后只做一件事，那就是“吃子”。当她遇见可以吃的棋子时，就迅速冲上去吃掉棋子。当然，她横、竖、斜都可走一或 N
//-1 步，可进可退。（引用自 百度百科 - 皇后 ） 
// 
// Related Topics 回溯算法 
// 👍 153 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        unordered_set<int> columns;
        unordered_set<int> diagonals1;
        unordered_set<int> diagonals2;
        int row = 0;
        count = backtrack(count, n, row, columns, diagonals1, diagonals2);
        return count;
    }

    int backtrack(int& count, int& n, int& row, unordered_set<int>& columns,
                   unordered_set<int>& diagonals1, unordered_set<int>& diagonals2) {
        if (row == n) {
            count++;
        }else{
            for (int i = 0; i < n; i++) {
                if (columns.find(i) != columns.end()){
                    continue;
                }
                int diagonal1 = row - i;
                if (diagonals1.find(diagonal1) != diagonals1.end()){
                    continue;
                }
                int diagonal2 = row + i;
                if (diagonals2.find(diagonal2) != diagonals2.end()){
                    continue;
                }
                columns.insert(i);
                diagonals1.insert(diagonal1);
                diagonals2.insert(diagonal2);
                row++;
                count = backtrack(count, n, row, columns, diagonals1, diagonals2);
                row--;
                columns.erase(i);
                diagonals1.erase(diagonal1);
                diagonals2.erase(diagonal2);
            }
        }
        return count;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
