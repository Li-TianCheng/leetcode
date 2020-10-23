//给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。 
//
// 请你找出这两个正序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。 
//
// 你可以假设 nums1 和 nums2 不会同时为空。 
//
// 
//
// 示例 1: 
//
// nums1 = [1, 3]
//nums2 = [2]
//
//则中位数是 2.0
// 
//
// 示例 2: 
//
// nums1 = [1, 2]
//nums2 = [3, 4]
//
//则中位数是 (2 + 3)/2 = 2.5
// 
// Related Topics 数组 二分查找 分治算法 
// 👍 2994 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        //method 1
        if(nums1.length > nums2.length){
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.length;
        int n = nums2.length;
        int max = 0;
        int min = 0;
        int left = 0;
        int right = m;
        while (left <= right){
            int i = (left + right) / 2;
            int j = (m + n + 1) / 2 - i;
            int nums1_i = (i == m ? Integer.MAX_VALUE : nums1[i]);
            int nums1_i_1 = (i == 0 ? Integer.MIN_VALUE : nums1[i-1]);
            int nums2_j = (j == n ? Integer.MAX_VALUE : nums2[j]);
            int nums2_j_1 = (j == 0 ? Integer.MIN_VALUE : nums2[j-1]);
            min = Math.min(nums1_i, nums2_j);
            max = Math.max(nums1_i_1, nums2_j_1);
            if(max <= min){
                break;
            }
            if(nums1_i_1> nums2_j_1){
                right = i - 1;
            }else {
                left = i + 1;
            }
        }
        return (m + n)  % 2 == 0 ? (max + min) / 2.0 : max;

        //method 2
//        int m = nums1.length;
//        int n = nums2.length;
//        return (m + n) % 2 == 0 ?
//                (getKthElement(nums1, nums2,(m+n)/2)+getKthElement(nums1, nums2,(m+n)/2+1))/2.0 :
//                getKthElement(nums1, nums2,(m+n)/2+1);
    }

//    public int getKthElement(int[] nums1, int[] nums2, int k){
//        int m = nums1.length;
//        int n = nums2.length;
//        int base1 = 0;
//        int base2 = 0;
//        while (true){
//            if(base1 == m){
//                return nums2[base2 + k - 1];
//            }
//            if(base2 == n){
//                return nums1[base1 + k - 1];
//            }
//            if(k == 1){
//                return Math.min(nums1[base1], nums2[base2]);
//            }
//            int half = k / 2;
//            int index1 = Math.min(base1+half, m) - 1;
//            int index2 = Math.min(base2+half, n) - 1;
//            if (nums1[index1] <= nums2[index2]){
//                k = k - (index1 - base1 + 1);
//                base1 = index1 + 1;
//            }else {
//                k = k - (index2 - base2 + 1);
//                base2 = index2 + 1;
//            }
//        }
//    }
}
//leetcode submit region end(Prohibit modification and deletion)
