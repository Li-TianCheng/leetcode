//给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c +
// d 的值与 target 相等？找出所有满足条件且不重复的四元组。 
//
// 注意： 
//
// 答案中不可以包含重复的四元组。 
//
// 示例： 
//
// 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
//
//满足要求的四元组集合为：
//[
//  [-1,  0, 0, 1],
//  [-2, -1, 1, 2],
//  [-2,  0, 0, 2]
//]
// 
// Related Topics 数组 哈希表 双指针 
// 👍 538 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> result = new ArrayList<>();
        if(nums.length < 4)
            return result;
        Arrays.sort(nums);
        for(int i=0; i < nums.length - 3; i++){
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            if(nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target)
                break;
            if(nums[i] + nums[nums.length-1] + nums[nums.length-2] + nums[nums.length-3] < target)
                continue;
            for(int j=i+1; j < nums.length - 2; j++){
                if(j > i + 1 && nums[j] == nums[j-1])
                    continue;
                if(nums[i] + nums[j] + nums[j+1] + nums[j+2] > target)
                    break;
                if(nums[i] + nums[j] + nums[nums.length-1] + nums[nums.length-2] < target)
                    continue;
                int left = j + 1;
                int right = nums.length - 1;
                while (left < right){
                    while (left < right && left > j+1 && nums[left] == nums[left-1])
                        left++;
                    while (left < right && right < nums.length-1 && nums[right] == nums[right+1])
                        right--;
                    if(left == right)
                        break;
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if(sum == target)
                        result.add(Arrays.asList(nums[i], nums[j], nums[left], nums[right]));
                    if(sum < target)
                        left++;
                    else
                        right--;
                }
            }
        }
        return result;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
