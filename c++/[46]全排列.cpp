//给定一个 没有重复 数字的序列，返回其所有可能的全排列。 
//
// 示例: 
//
// 输入: [1,2,3]
//输出:
//[
//  [1,2,3],
//  [1,3,2],
//  [2,1,3],
//  [2,3,1],
//  [3,1,2],
//  [3,2,1]
//] 
// Related Topics 回溯算法 
// 👍 943 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_set<int> hashSet;
        vector<int> tem;
        backtrack(nums, hashSet, tem);
        return result;
    }

    void backtrack(const vector<int>& nums, unordered_set<int>& hashSet, vector<int>& tem){
        if (hashSet.size() == nums.size()){
            result.push_back(tem);
            return;
        }
        for (int i = 0; i < nums.size(); i++){
            if (hashSet.find(nums[i]) == hashSet.end()){
                hashSet.insert(nums[i]);
                tem.push_back(nums[i]);
                backtrack(nums, hashSet, tem);
                tem.pop_back();
                hashSet.erase(nums[i]);
            }
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
