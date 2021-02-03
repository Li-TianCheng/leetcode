//给定一个整数数组 nums 。区间和 S(i, j) 表示在 nums 中，位置从 i 到 j 的元素之和，包含 i 和 j (i ≤ j)。 
//
// 请你以下标 i （0 <= i <= nums.length ）为起点，元素个数逐次递增，计算子数组内的元素和。 
//
// 当元素和落在范围 [lower, upper] （包含 lower 和 upper）之内时，记录子数组当前最末元素下标 j ，记作 有效 区间和 S(i,
// j) 。 
//
// 求数组中，值位于范围 [lower, upper] （包含 lower 和 upper）之内的 有效 区间和的个数。 
//
// 
//
// 注意： 
//最直观的算法复杂度是 O(n2) ，请在此基础上优化你的算法。 
//
// 
//
// 示例： 
//
// 
//输入：nums = [-2,5,-1], lower = -2, upper = 2,
//输出：3 
//解释：
//下标 i = 0 时，子数组 [-2]、[-2,5]、[-2,5,-1]，对应元素和分别为 -2、3、2 ；其中 -2 和 2 落在范围 [lower = 
//-2, upper = 2] 之间，因此记录有效区间和 S(0,0)，S(0,2) 。
//下标 i = 1 时，子数组 [5]、[5,-1] ，元素和 5、4 ；没有满足题意的有效区间和。
//下标 i = 2 时，子数组 [-1] ，元素和 -1 ；记录有效区间和 S(2,2) 。
//故，共有 3 个有效区间和。 
//
// 
//
// 提示： 
//
// 
// 0 <= nums.length <= 10^4 
// 
// Related Topics 排序 树状数组 线段树 二分查找 分治算法 
// 👍 288 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    long[] temp;
    int result = 0;
    public int countRangeSum(int[] nums, int lower, int upper) {
        long[] preSum = new long[nums.length+1];
        for (int i = 0; i < nums.length; i++){
            preSum[i+1] = preSum[i] + nums[i];
        }
        temp = preSum.clone();
        mergeSort(preSum, 0, preSum.length, lower, upper);
        return result;
    }

    public void mergeSort(long[] nums, int x, int y, long lower, long upper) {
        if (x >= y-1){
            return;
        }
        int mid = (x + y) >> 1;
        mergeSort(nums, x, mid, lower, upper);
        mergeSort(nums, mid, y, lower, upper);
        merge(nums, x, mid, y, lower, upper);
    }

    public void merge(long[] nums, int x, int mid, int y, long lower, long upper){
        int idx = x;
        int left = x;
        int right = mid;
        int low = mid;
        int up = mid;
        for (int i = x; i < mid; i++) {
            while (low < y){
                if (nums[low] - nums[i] >= lower){
                    break;
                }
                low++;
            }
            if (up < low){
                up = low;
            }
            while (up < y){
                if (nums[up] - nums[i] > upper){
                    break;
                }
                up++;
            }
            result += up - low;
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
