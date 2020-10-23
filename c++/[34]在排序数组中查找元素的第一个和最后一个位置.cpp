//给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。 
//
// 你的算法时间复杂度必须是 O(log n) 级别。 
//
// 如果数组中不存在目标值，返回 [-1, -1]。 
//
// 示例 1: 
//
// 输入: nums = [5,7,7,8,8,10], target = 8
//输出: [3,4] 
//
// 示例 2: 
//
// 输入: nums = [5,7,7,8,8,10], target = 6
//输出: [-1,-1] 
// Related Topics 数组 二分查找 
// 👍 605 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result {-1, -1};
        if (nums.size() == 0)
            return result;
        int&& left = search(nums, target, true);
        left = nums[left] == target ? left : -1;
        if (left == -1)
            return result;
        int&& right = search(nums, target, false);
        right = nums[right] == target ? right : right-1;
        result[0] = left;
        result[1] = right;
        return result;
    }

    static int search(const vector<int>& nums, const int& target, const bool& m) {
        int start = 0;
        int end = nums.size() - 1;
        while (start < end) {
            int mid = (start + end) >> 1;
            if (nums[mid] > target || (m && nums[mid] == target)) {
                end = mid;
            } else
                start = mid + 1;
        }
        return start;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
