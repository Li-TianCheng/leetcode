//给定一个 m x n 整数矩阵 matrix ，找出其中 最长递增路径 的长度。 
//
// 对于每个单元格，你可以往上，下，左，右四个方向移动。 你 不能 在 对角线 方向上移动或移动到 边界外（即不允许环绕）。 
//
// 
//
// 示例 1： 
//
// 
//输入：matrix = [[9,9,4],[6,6,8],[2,1,1]]
//输出：4 
//解释：最长递增路径为 [1, 2, 6, 9]。 
//
// 示例 2： 
//
// 
//输入：matrix = [[3,4,5],[3,2,6],[2,2,1]]
//输出：4 
//解释：最长递增路径是 [3, 4, 5, 6]。注意不允许在对角线方向上移动。
// 
//
// 示例 3： 
//
// 
//输入：matrix = [[1]]
//输出：1
// 
//
// 
//
// 提示： 
//
// 
// m == matrix.length 
// n == matrix[i].length 
// 1 <= m, n <= 200 
// 0 <= matrix[i][j] <= 231 - 1 
// 
// Related Topics 深度优先搜索 拓扑排序 记忆化 
// 👍 417 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public int longestIncreasingPath(int[][] matrix) {
        int[][] cache = new int[matrix.length][matrix[0].length];
        int result = 0;
        for (int i = 0; i < matrix.length; i++){
            for (int j = 0; j < matrix[0].length; j++){
                result = Math.max(result, dfs(matrix, cache, i, j));
            }
        }
        return result;
    }

    private int dfs(int[][] matrix, int[][] cache, int x, int y){
        if (cache[x][y] != 0){
            return cache[x][y];
        }
        int curr = 1;
        if (x != 0 && matrix[x-1][y] > matrix[x][y]){
            if (cache[x-1][y] == 0){
                cache[x-1][y] = dfs(matrix, cache, x-1, y);
            }
            curr = Math.max(curr, cache[x-1][y]+1);
        }
        if (x != matrix.length-1 && matrix[x+1][y] > matrix[x][y]){
            if (cache[x+1][y] == 0){
                cache[x+1][y] = dfs(matrix, cache, x+1, y);
            }
            curr = Math.max(curr, cache[x+1][y]+1);
        }
        if (y != 0 && matrix[x][y-1] > matrix[x][y]){
            if (cache[x][y-1] == 0){
                cache[x][y-1] = dfs(matrix, cache, x, y-1);
            }
            curr = Math.max(curr, cache[x][y-1]+1);
        }
        if (y != matrix[0].length-1 && matrix[x][y+1] > matrix[x][y]){
            if (cache[x][y+1] == 0){
                cache[x][y+1] = dfs(matrix, cache, x, y+1);
            }
            curr = Math.max(curr, cache[x][y+1]+1);
        }
        cache[x][y] = curr;
        return curr;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
