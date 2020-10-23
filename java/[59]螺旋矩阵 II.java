//给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。 
//
// 示例: 
//
// 输入: 3
//输出:
//[
// [ 1, 2, 3 ],
// [ 8, 9, 4 ],
// [ 7, 6, 5 ]
//] 
// Related Topics 数组 
// 👍 242 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public int[][] generateMatrix(int n) {
        int[][] result = new int[n][n];
        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = n - 1;
        int count = 1;
        while (top <= bottom && left <= right) {
            if (top == bottom && left == right)
                result[top][left] = count;
            for (int i = left; i < right; i++){
                result[top][i] = count;
                count++;
            }
            for (int i = top; i < bottom; i++){
                result[i][right] = count;
                count++;
            }
            for (int i = right; i > left; i--){
                result[bottom][i] = count;
                count++;
            }
            for (int i = bottom; i > top; i--){
                result[i][left] = count;
                count++;
            }
            top++;
            left++;
            right--;
            bottom--;
        }
        return result;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
