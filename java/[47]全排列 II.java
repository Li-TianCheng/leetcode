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
// 👍 385 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    List<List<Integer>> result = new ArrayList<>();

    public List<List<Integer>> permuteUnique(int[] nums) {
        if (nums.length == 0)
            return result;
        Arrays.sort(nums);
        boolean[] used = new boolean[nums.length];
        backtrace(nums, 0, used, new ArrayList<>());
        return result;
    }

    private void backtrace(int[] nums, int depth, boolean[] used, List<Integer> temp){
        if (depth == nums.length){
            result.add(new ArrayList<>(temp));
            return;
        }
        for (int i = 0; i < nums.length; i++){
            if (used[i])
                continue;
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
                continue;
            temp.add(nums[i]);
            used[i] = true;
            backtrace(nums, depth + 1, used, temp);
            used[i] = false;
            temp.remove(temp.size() - 1);
        }
    }
}
//leetcode submit region end(Prohibit modification and deletion)
