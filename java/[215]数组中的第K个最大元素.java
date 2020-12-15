//在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。 
//
// 示例 1: 
//
// 输入: [3,2,1,5,6,4] 和 k = 2
//输出: 5
// 
//
// 示例 2: 
//
// 输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
//输出: 4 
//
// 说明: 
//
// 你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。 
// Related Topics 堆 分治算法 
// 👍 813 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    // heap sort
//    public int findKthLargest(int[] nums, int k) {
//        buildMaxHeap(nums, nums.length);
//        TopK(nums, nums.length, k);
//        return nums[nums.length-k];
//    }
//
//    private void MaxHeapFixUp(int[] nums, int length, int root){
//        int left = root * 2 + 1;
//        int right = root * 2 + 2;
//        int leftVal = left >= length ? Integer.MIN_VALUE : nums[left];
//        int rightVal = right >= length ? Integer.MIN_VALUE : nums[right];
//        int maxIndex = root;
//        if (nums[root] < leftVal){
//            maxIndex = left;
//        }
//        if (nums[maxIndex] < rightVal){
//            maxIndex = right;
//        }
//        if (maxIndex != root){
//            int temp = nums[root];
//            nums[root] = nums[maxIndex];
//            nums[maxIndex] = temp;
//            MaxHeapFixUp(nums, length, maxIndex);
//        }
//    }
//
//    private void buildMaxHeap(int[] nums, int length){
//        for (int i = (length-1)/2; i >= 0; i--){
//            MaxHeapFixUp(nums, length, i);
//        }
//    }
//
//    private void TopK(int[] nums, int length, int k){
//        if (nums.length-length == k){
//            return;
//        }
//        int temp = nums[0];
//        nums[0] = nums[length-1];
//        nums[length-1] = temp;
//        MaxHeapFixUp(nums, length-1, 0);
//        TopK(nums, length-1, k);
//    }

    //quick sort
    public int findKthLargest(int[] nums, int k) {
        quickCheck(nums, 0, nums.length, k);
        return nums[k-1];
    }

    private void quickCheck(int[] nums, int left, int right, int k){
        if (left >= right){
            return;
        }
        Random random = new Random();
        int keyIndex = random.nextInt(right-left)+left;
        int tem = nums[left];
        nums[left] = nums[keyIndex];
        nums[keyIndex] = tem;
        int key = nums[left];
        int begin = left+1;
        int end = right;
        while (begin < end){
            if (nums[begin] >= key){
                begin++;
                continue;
            }
            if (nums[end-1] < key){
                end--;
                continue;
            }
            int temp = nums[begin];
            nums[begin] = nums[end-1];
            nums[end-1] = temp;
        }
        nums[left] = nums[begin-1];
        nums[begin-1] = key;
        if (begin == k){
            return;
        }
        if (begin > k){
            quickCheck(nums, left, begin-1, k);
        }else{
            quickCheck(nums, begin, right, k);
        }
    }
}
//leetcode submit region end(Prohibit modification and deletion)
