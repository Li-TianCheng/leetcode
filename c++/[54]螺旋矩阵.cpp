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
// 👍 517 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return result;
        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;
        while (left <= right && top <= bottom){
            for (int i = left; i <= right; ++i){
                result.push_back(matrix[top][i]);
            }
            for (int j = top+1; j <= bottom; ++j){
                result.push_back(matrix[j][right]);
            }
            if (left < right && top < bottom){
                for (int m = right-1; m > left; m--){
                    result.push_back(matrix[bottom][m]);
                }
                for (int n = bottom; n > top; n--){
                    result.push_back(matrix[n][left]);
                }
            }
            left++;
            right--;
            top++;
            bottom--;
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
