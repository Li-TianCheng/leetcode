//给定长度分别为 m 和 n 的两个数组，其元素由 0-9 构成，表示两个自然数各位上的数字。现在从这两个数组中选出 k (k <= m + n) 个数字拼接
//成一个新的数，要求从同一个数组中取出的数字保持其在原数组中的相对顺序。 
//
// 求满足该条件的最大数。结果返回一个表示该最大数的长度为 k 的数组。 
//
// 说明: 请尽可能地优化你算法的时间和空间复杂度。 
//
// 示例 1: 
//
// 输入:
//nums1 = [3, 4, 6, 5]
//nums2 = [9, 1, 2, 5, 8, 3]
//k = 5
//输出:
//[9, 8, 6, 5, 3] 
//
// 示例 2: 
//
// 输入:
//nums1 = [6, 7]
//nums2 = [6, 0, 4]
//k = 5
//输出:
//[6, 7, 6, 0, 4] 
//
// 示例 3: 
//
// 输入:
//nums1 = [3, 9]
//nums2 = [8, 9]
//k = 3
//输出:
//[9, 8, 9] 
// Related Topics 贪心算法 动态规划 
// 👍 326 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public int[] maxNumber(int[] nums1, int[] nums2, int k) {
        int[] result = new int[1];
        for (int i = 0; i <= k; i++){
            if (i > nums1.length || k-i > nums2.length){
                continue;
            }
            int[] sub1 = getMaxSubset(nums1, i);
            int[] sub2 = getMaxSubset(nums2, k-i);
            result = compare(result, merge(sub1, sub2));
        }
        return result;
    }

    private int[] getMaxSubset(int[] nums, int k){
        if (k == 0){
            return new int[0];
        }
        Deque<Integer> queue = new LinkedList<Integer>();
        for(int i = 0; i < nums.length; i++){
            if (queue.isEmpty()){
                queue.offerLast(nums[i]);
            }else {
                while (!queue.isEmpty()){
                    int curr = queue.getLast();
                    if (nums[i] > curr && queue.size()+nums.length-i > k){
                        queue.pollLast();
                    }else {
                        break;
                    }
                }
                if (queue.size() < k){
                    queue.offerLast(nums[i]);
                }
            }
        }
        int[] result = new int[queue.size()];
        for (int i = 0; i < result.length; i++) {
            result[i] = queue.pollFirst();
        }
        return result;
    }

    private int[] merge(int[] nums1, int[] nums2){
        int[] result = new int[nums1.length+nums2.length];
        int index1 = 0;
        int index2 = 0;
        while (index1 < nums1.length || index2 < nums2.length){
            if (index1 >= nums1.length){
                result[index1+index2] = nums2[index2];
                index2++;
            }else if (index2 >= nums2.length){
                result[index1+index2] = nums1[index1];
                index1++;
            }else {
                int num1 = nums1[index1];
                int num2 = nums2[index2];
                if (num1 > num2){
                    result[index1+index2] = num1;
                    index1++;
                }else if (num1 < num2){
                    result[index1+index2] = num2;
                    index2++;
                }else {
                    int index1Copy = index1+1;
                    int index2Copy = index2+1;
                    while (true){
                        int nextNum1 = index1Copy >= nums1.length ? Integer.MIN_VALUE : nums1[index1Copy];
                        int nextNum2 = index2Copy >= nums2.length ? Integer.MIN_VALUE : nums2[index2Copy];
                        if (nextNum1 > nextNum2){
                            result[index1+index2] = num1;
                            index1++;
                            break;
                        }else if (nextNum1 < nextNum2){
                            result[index1+index2] = num2;
                            index2++;
                            break;
                        }else {
                            if (nextNum1 == Integer.MIN_VALUE){
                                result[index1+index2] = num1;
                                index1++;
                                break;
                            }
                        }
                        index1Copy++;
                        index2Copy++;
                    }
                }
            }
        }
        return result;
    }

    private int[] compare(int[] nums1, int[] nums2){
        if (nums1.length > nums2.length){
            return nums1;
        }else if (nums1.length < nums2.length){
            return nums2;
        }else{
            for (int i = 0; i < nums1.length; i++){
                if (nums1[i] > nums2[i]){
                    return nums1;
                }
                if (nums1[i] < nums2[i]){
                    return nums2;
                }
            }
        }
        return nums1;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
