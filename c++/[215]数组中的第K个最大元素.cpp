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
public:
    // heap sort
//    int findKthLargest(vector<int>& nums, int k) {
//        buildMaxHeap(nums, nums.size());
//        TopK(nums, nums.size(), k);
//        return nums[nums.size()-k];
//    }
//
//    void maxHeapFixUp(vector<int>& nums, int length, int root){
//        int left = root * 2 + 1;
//        int right = root * 2 + 2;
//        int leftValue = left >= length ? INT_MIN : nums[left];
//        int rightValue = right >= length ? INT_MIN : nums[right];
//        int maxIndex = root;
//        if (nums[root] < leftValue){
//            maxIndex = left;
//        }
//        if (nums[maxIndex] < rightValue){
//            maxIndex = right;
//        }
//        if (maxIndex != root){
//            int temp = nums[root];
//            nums[root] = nums[maxIndex];
//            nums[maxIndex] = temp;
//            maxHeapFixUp(nums, length, maxIndex);
//        }
//    }
//
//    void buildMaxHeap(vector<int>& nums, int length){
//        for (int i = (length-1)/2; i>= 0; i--){
//            maxHeapFixUp(nums, length, i);
//        }
//    }
//
//    void TopK(vector<int>& nums, int length, int k){
//        if (nums.size()-length == k){
//            return;
//        }
//        int temp = nums[0];
//        nums[0] = nums[length-1];
//        nums[length-1] = temp;
//        maxHeapFixUp(nums, length-1, 0);
//        TopK(nums, length-1, k);
//    }

    //quick sort
    int findKthLargest(vector<int>& nums, int k) {
        quickCheck(nums, 0, nums.size(), k);
        return nums[k-1];
    }

    void quickCheck(vector<int>& nums, int left, int right, int k){
        if (left >= right){
            return;
        }
        int keyIndex = rand() % (right-left) + left;
        int tem = nums[left];
        nums[left] = nums[keyIndex];
        nums[keyIndex] = tem;
        int key = nums[left];
        int begin = left + 1;
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
};
//leetcode submit region end(Prohibit modification and deletion)
