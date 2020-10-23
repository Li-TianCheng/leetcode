//给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复
//的三元组。 
//
// 注意：答案中不可以包含重复的三元组。 
//
// 
//
// 示例： 
//
// 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
//
//满足要求的三元组集合为：
//[
//  [-1, 0, 1],
//  [-1, -1, 2]
//]
// 
// Related Topics 数组 双指针 
// 👍 2617 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() < 3)
            return result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (nums[i] > 0)
                break;
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            int target = -nums[i];
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right){
                while (left < right && left > i + 1 && nums[left] == nums[left-1])
                    left++;
                while (left < right && right < nums.size() - 1 && nums[right] == nums[right+1])
                    right--;
                if (left == right)
                    break;
                if (nums[left] + nums[right] == target)
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                if (nums[left] + nums[right] < target)
                    left++;
                else
                    right--;
            }
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
