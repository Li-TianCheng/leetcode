//给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。 
//
// candidates 中的数字可以无限制重复被选取。 
//
// 说明： 
//
// 
// 所有数字（包括 target）都是正整数。 
// 解集不能包含重复的组合。 
// 
//
// 示例 1： 
//
// 输入：candidates = [2,3,6,7], target = 7,
//所求解集为：
//[
//  [7],
//  [2,2,3]
//]
// 
//
// 示例 2： 
//
// 输入：candidates = [2,3,5], target = 8,
//所求解集为：
//[
//  [2,2,2,2],
//  [2,3,3],
//  [3,5]
//] 
//
// 
//
// 提示： 
//
// 
// 1 <= candidates.length <= 30 
// 1 <= candidates[i] <= 200 
// candidate 中的每个元素都是独一无二的。 
// 1 <= target <= 500 
// 
// Related Topics 数组 回溯算法 
// 👍 977 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> result;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> res;
        backtrack(candidates, target, 0, 0, res);
        return result;
    }

    void backtrack(const vector<int>& candidates, const int& target, const int& idx, const int& temp, vector<int>& res) {
        if (temp == target){
            result.push_back(res);
            return;
        }
        for (int i=idx; i < candidates.size(); i++){
            if (temp + candidates[i] > target)
                break;
            res.push_back(candidates[i]);
            backtrack(candidates, target, i, temp+candidates[i], res);
            res.pop_back();
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
