//给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和
//。假定每组输入只存在唯一答案。 
//
// 
//
// 示例： 
//
// 输入：nums = [-1,2,1,-4], target = 1
//输出：2
//解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。
// 
//
// 
//
// 提示： 
//
// 
// 3 <= nums.length <= 10^3 
// -10^3 <= nums[i] <= 10^3 
// -10^4 <= target <= 10^4 
// 
// Related Topics 数组 双指针 
// 👍 537 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int best = 0;
        int deference = Integer.MAX_VALUE;
        for(int i=0; i < nums.length - 2; i++){
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            int left = i + 1;
            int right = nums.length - 1;
            while (left < right){
//                while (left < right && left > i + 1 && nums[left] == nums[left-1])
//                    left++;
//                while (left < right && right < nums.length - 1 && nums[right] == nums[right+1])
//                    right--;
//                if(left == right)
//                    break;
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == target)
                    return sum;
                if(Math.abs(sum - target) < deference){
                    best = sum;
                    deference = Math.abs(sum - target);
                }
                if(sum < target)
                    left++;
                else
                    right--;
            }
        }
        return best;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
