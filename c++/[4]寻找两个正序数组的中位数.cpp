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
// 👍 3177 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()){
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();
        int tem_max = 0;
        int tem_min = 0;
        int left = 0;
        int right = m;
        while (left <= right){
            int i = (left + right) / 2;
            int j = (m + n + 1) / 2 - i;
            int nums1_i = (i == m ? INT32_MAX : nums1[i]);
            int nums1_i_1 = (i == 0 ? INT32_MIN : nums1[i - 1]);
            int nums2_j = (j == n ? INT32_MAX : nums2[j]);
            int nums2_j_1 = (j == 0 ? INT32_MIN : nums2[j - 1]);
            tem_min = min(nums1_i, nums2_j);
            tem_max = max(nums1_i_1, nums2_j_1);
            if (tem_max <= tem_min){
                break;
            }
            if (nums1_i_1 > nums2_j_1){
                right = i - 1;
            } else{
                left = i + 1;
            }
        }
        return (m + n) % 2 == 0 ? (tem_max + tem_min) / 2.0 : tem_max;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
