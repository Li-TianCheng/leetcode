//给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。 
//
// 说明：解集不能包含重复的子集。 
//
// 示例: 
//
// 输入: [1,2,2]
//输出:
//[
//  [2],
//  [1],
//  [1,2,2],
//  [2,2],
//  [1,2],
//  []
//] 
// Related Topics 数组 回溯算法 
// 👍 326 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        vector<int> tem;
        backtrack(nums, tem, 0, result);
        return result;
    }

    void backtrack(vector<int>& nums, vector<int>& tem, int start, vector<vector<int>>& result){
        result.push_back(tem);
        for (int i = start; i < nums.size(); i++) {
            if (i != start && nums[i] == nums[i-1])
                continue;
            tem.push_back(nums[i]);
            backtrack(nums, tem, i+1, result);
            tem.pop_back();
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
