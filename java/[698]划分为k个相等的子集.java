//给定一个整数数组 nums 和一个正整数 k，找出是否有可能把这个数组分成 k 个非空子集，其总和都相等。 
//
// 示例 1： 
//
// 输入： nums = [4, 3, 2, 3, 5, 2, 1], k = 4
//输出： True
//说明： 有可能将其分成 4 个子集（5），（1,4），（2,3），（2,3）等于总和。 
//
// 
//
// 提示： 
//
// 
// 1 <= k <= len(nums) <= 16 
// 0 < nums[i] < 10000 
// 
// Related Topics 递归 动态规划 
// 👍 307 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public boolean canPartitionKSubsets(int[] nums, int k) {
        int target = 0;
        for (int num : nums){
            target += num;
        }
        if (target % k != 0){
            return false;
        }
        target /= k;
        boolean[] visited = new boolean[nums.length];
        Arrays.sort(nums);
        return backtrack(nums, visited, target, k, 0);
    }

    private boolean backtrack(int[] nums, boolean[] visited, final int target, int k, int currSum){
        if (k == 0){
            return true;
        }
        for (int i = nums.length-1; i >= 0; i--){
            if (visited[i]){
                continue;
            }
            if (i > 0 && nums[i] == nums[i-1] && !visited[i-1]){
                continue;
            }
            if (nums[i]+currSum < target){
                visited[i] = true;
                if (backtrack(nums, visited, target, k, nums[i]+currSum)){
                    return true;
                }
                visited[i] = false;
            }else if (nums[i]+currSum == target){
                visited[i] = true;
                if (backtrack(nums, visited, target, k-1, 0)){
                    return true;
                }
                visited[i] = false;
            }else{
                return false;
            }
        }
        return false;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
