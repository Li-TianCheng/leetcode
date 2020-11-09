//给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。 
//
// 
//
// 在杨辉三角中，每个数是它左上方和右上方的数的和。 
//
// 示例: 
//
// 输入: 3
//输出: [1,3,3,1]
// 
//
// 进阶： 
//
// 你可以优化你的算法到 O(k) 空间复杂度吗？ 
// Related Topics 数组 
// 👍 195 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        vector<int> temp;
        for (int i = 0; i < rowIndex+1; i++) {
            result.clear();
            for (int j = 0; j < temp.size(); j++) {
                int num1 = j-1 < 0 ? 0 : temp[j-1];
                int num2 = temp[j];
                result.push_back(num1+num2);
            }
            result.push_back(1);
            temp.assign(result.begin(), result.end());
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
