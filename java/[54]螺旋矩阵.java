//给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。 
//
// 示例 1: 
//
// 输入:
//[
// [ 1, 2, 3 ],
// [ 4, 5, 6 ],
// [ 7, 8, 9 ]
//]
//输出: [1,2,3,6,9,8,7,4,5]
// 
//
// 示例 2: 
//
// 输入:
//[
//  [1, 2, 3, 4],
//  [5, 6, 7, 8],
//  [9,10,11,12]
//]
//输出: [1,2,3,4,8,12,11,10,9,5,6,7]
// 
// Related Topics 数组 
// 👍 497 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> result = new ArrayList<>();
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0)
            return result;
        int top = 0;
        int buttom = matrix.length - 1;
        int left = 0;
        int right = matrix[0].length - 1;
        while (left <= right && top <= buttom){
            for (int i = left; i <= right; i++)
                result.add(matrix[top][i]);
            for (int j = top+1; j <= buttom; j++)
                result.add(matrix[j][right]);
            if (left < right && top < buttom){
                for (int m = right-1; m > left; m--)
                    result.add(matrix[buttom][m]);
                for (int n = buttom; n > top; n--)
                    result.add(matrix[n][left]);
            }
            left++;
            right--;
            top++;
            buttom--;
        }
        return result;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
