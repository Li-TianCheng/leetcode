//给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。 
//
// 
//
// 在杨辉三角中，每个数是它左上方和右上方的数的和。 
//
// 示例: 
//
// 输入: 5
//输出:
//[
//     [1],
//    [1,1],
//   [1,2,1],
//  [1,3,3,1],
// [1,4,6,4,1]
//] 
// Related Topics 数组 
// 👍 372 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for (int i = 0; i < numRows; i++){
            vector<int> temp;
            if (i == 0){
                temp.push_back(1);
            }else{
                for (int j = 0; j < i; j++){
                    int num1 = j-1 < 0 ? 0 : result[i-1][j-1];
                    int num2 = result[i-1][j];
                    temp.push_back(num1+num2);
                }
                temp.push_back(1);
            }
            result.push_back(temp);
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
