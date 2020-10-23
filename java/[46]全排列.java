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
// 👍 857 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    List<List<Integer>> result = new ArrayList<>();
    public List<List<Integer>> permute(int[] nums) {
        backtarce(nums, new HashSet(), new ArrayList<>());
        return result;
    }

    private void backtarce(int[] nums, HashSet hashSet, List<Integer> tem){
        if (hashSet.size() == nums.length){
            result.add(new ArrayList<>(tem));
            return;
        }
        for (int i = 0; i < nums.length; i++){
            if (!hashSet.contains(nums[i])){
                hashSet.add(nums[i]);
                tem.add(nums[i]);
                backtarce(nums, hashSet, tem);
                tem.remove(tem.size() - 1);
                hashSet.remove(nums[i]);
            }
        }
    }
}
//leetcode submit region end(Prohibit modification and deletion)
