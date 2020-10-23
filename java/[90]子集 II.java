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
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        Arrays.sort(nums);
        List<Integer> tem = new ArrayList<>();
        backtrace(nums, tem, 0, result);
        return result;
    }

    private void backtrace(int[] nums, List<Integer> tem, int start, List<List<Integer>> result){
        result.add(new ArrayList<>(tem));
        for (int i = start; i < nums.length; i++){
            if (i != start && nums[i] == nums[i-1])
                continue;
            tem.add(nums[i]);
            backtrace(nums, tem, i+1, result);
            tem.remove(tem.size() - 1);
        }
    }
}
//leetcode submit region end(Prohibit modification and deletion)
