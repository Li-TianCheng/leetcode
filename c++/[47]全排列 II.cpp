//给定一个可包含重复数字的序列，返回所有不重复的全排列。 
//
// 示例: 
//
// 输入: [1,1,2]
//输出:
//[
//  [1,1,2],
//  [1,2,1],
//  [2,1,1]
//] 
// Related Topics 回溯算法 
// 👍 487 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if (nums.empty())
            return result;
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        vector<int> tem;
        int depth = 0;
        backtrack(nums, depth, used, tem);
        return result;
    }

    void backtrack(const vector<int>& nums, int& depth, vector<bool>& used, vector<int>& tem){
        if (depth == nums.size()){
            result.push_back(tem);
            return;
        }
        for (int i = 0; i < nums.size(); i++){
            if (used[i])
                continue;
            if (i > 0 && nums[i] == nums[i-1] && !used[i-1])
                continue;
            tem.push_back(nums[i]);
            used[i] = true;
            depth++;
            backtrack(nums, depth, used, tem);
            used[i] = false;
            depth--;
            tem.pop_back();
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
