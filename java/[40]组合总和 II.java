//给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。 
//
// candidates 中的每个数字在每个组合中只能使用一次。 
//
// 说明： 
//
// 
// 所有数字（包括目标数）都是正整数。 
// 解集不能包含重复的组合。 
// 
//
// 示例 1: 
//
// 输入: candidates = [10,1,2,7,6,1,5], target = 8,
//所求解集为:
//[
//  [1, 7],
//  [1, 2, 5],
//  [2, 6],
//  [1, 1, 6]
//]
// 
//
// 示例 2: 
//
// 输入: candidates = [2,5,2,1,2], target = 5,
//所求解集为:
//[
//  [1,2,2],
//  [5]
//] 
// Related Topics 数组 回溯算法 
// 👍 342 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    List<List<Integer>> result = new ArrayList<>();

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<Integer> res = new ArrayList<>();
        backtrace(candidates, target, -1, 0, res);
        return result;
    }

    private void backtrace(int[] candidates, int target, int idx, int temp, List<Integer> res){
        if (temp == target){
            result.add(new ArrayList<>(res));
            return;
        }
        for (int i = idx + 1; i < candidates.length; i++){
            if(i > idx + 1 && candidates[i] == candidates[i - 1])
                continue;
            if(temp + candidates[i] > target)
                break;
            res.add(candidates[i]);
            backtrace(candidates, target, i, temp + candidates[i], res);
            res.remove(res.size() - 1);
        }
    }
}
//leetcode submit region end(Prohibit modification and deletion)
