//给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。 
//
// 
//
// 进阶：你可以设计并实现时间复杂度为 O(n) 的解决方案吗？ 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [100,4,200,1,3,2]
//输出：4
//解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。 
//
// 示例 2： 
//
// 
//输入：nums = [0,3,7,2,5,8,4,6,0,1]
//输出：9
// 
//
// 
//
// 提示： 
//
// 
// 0 <= nums.length <= 104 
// -109 <= nums[i] <= 109 
// 
// Related Topics 并查集 数组 
// 👍 606 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    HashSet<Integer> set = new HashSet<Integer>();

    public int longestConsecutive(int[] nums) {
        int result = 0;
        for (int num : nums) {
            set.add(num);
        }
        for (int num : nums){
            if (!set.contains(num-1)){
                result = Math.max(result, find(num+1)-num);
            }
        }
        return result;
    }

    private int find(int num){
        return set.contains(num) ? find(num+1) : num;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
