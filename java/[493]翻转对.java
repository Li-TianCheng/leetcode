//给定一个数组 nums ，如果 i < j 且 nums[i] > 2*nums[j] 我们就将 (i, j) 称作一个重要翻转对。 
//
// 你需要返回给定数组中的重要翻转对的数量。 
//
// 示例 1: 
//
// 
//输入: [1,3,2,3,1]
//输出: 2
// 
//
// 示例 2: 
//
// 
//输入: [2,4,3,5,1]
//输出: 3
// 
//
// 注意: 
//
// 
// 给定数组的长度不会超过50000。 
// 输入数组中的所有数字都在32位整数的表示范围内。 
// 
// Related Topics 排序 树状数组 线段树 二分查找 分治算法 
// 👍 257 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    int[] temp;
    int result = 0;
    public int reversePairs(int[] nums) {
        temp = new int[nums.length];
        mergeSort(nums, 0, nums.length);
        return result;
    }

    public void mergeSort(int[] nums, int x, int y) {
        if (x >= y-1){
            return;
        }
        int mid = (x + y) >> 1;
        mergeSort(nums, x, mid);
        mergeSort(nums, mid, y);
        merge(nums, x, mid, y);
    }

    public void merge(int[] nums, int x, int mid, int y) {
        int idx = x;
        int left = x;
        int right = mid;
        int l = x;
        for (int i = mid; i < y; i++) {
            while (l < mid){
                if ((long)nums[l] > (long)2*nums[i]){
                    result += mid - l;
                    break;
                }
                l++;
            }
        }
        while (left < mid || right < y){
            long tempLeft = left < mid ? nums[left] : Long.MAX_VALUE;
            long tempRight = right < y ? nums[right] : Long.MAX_VALUE;
            if (tempLeft > tempRight){
                temp[idx] = nums[right];
                right++;
            }else{
                temp[idx] = nums[left];
                left++;
            }
            idx++;
        }
        for (int i = x; i < y; i++){
            nums[i] = temp[i];
        }
    }
}
//leetcode submit region end(Prohibit modification and deletion)
