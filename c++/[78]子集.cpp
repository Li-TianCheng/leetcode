//给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。 
//
// 说明：解集不能包含重复的子集。 
//
// 示例: 
//
// 输入: nums = [1,2,3]
//输出:
//[
//  [3],
//  [1],
//  [2],
//  [1,2,3],
//  [1,3],
//  [2,3],
//  [1,2],
//  []
//] 
// Related Topics 位运算 数组 回溯算法 
// 👍 848 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> result;

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        backtrack(nums, 0, temp);
        return result;
    }

    void backtrack(vector<int>& nums, int start, vector<int>& temp){
        result.push_back(temp);
        for (int i = start; i < nums.size(); i++) {
            temp.push_back(nums[i]);
            backtrack(nums, i+1, temp);
            temp.pop_back();
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
