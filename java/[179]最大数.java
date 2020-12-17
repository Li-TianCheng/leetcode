//给定一组非负整数 nums，重新排列它们每个数字的顺序（每个数字不可拆分）使之组成一个最大的整数。 
//
// 注意：输出结果可能非常大，所以你需要返回一个字符串而不是整数。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [10,2]
//输出："210" 
//
// 示例 2： 
//
// 
//输入：nums = [3,30,34,5,9]
//输出："9534330"
// 
//
// 示例 3： 
//
// 
//输入：nums = [1]
//输出："1"
// 
//
// 示例 4： 
//
// 
//输入：nums = [10]
//输出："10"
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 100 
// 0 <= nums[i] <= 109 
// 
// Related Topics 排序 
// 👍 440 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public String largestNumber(int[] nums) {
        if (nums.length == 0){
            return "";
        }
        quickSort(nums, 0, nums.length);
        if (nums[0] == 0){
            return "0";
        }
        StringBuilder sb = new StringBuilder();
        for (int num : nums) {
            sb.append(num);
        }
        return sb.toString();
    }

    private void quickSort(int[] nums, int left, int right) {
        if (left >= right){
            return;
        }
        int begin = left+1;
        int end = right;
        Random random = new Random();
        int keyIndex = random.nextInt(right-left) + left;
        int tem = nums[left];
        nums[left] = nums[keyIndex];
        nums[keyIndex] = tem;
        int key = nums[left];
        while (begin < end) {
            if (compare(nums[begin], key)){
                begin++;
                continue;
            }
            if (compare(key, nums[end-1])){
                end--;
                continue;
            }
            int temp = nums[begin];
            nums[begin] = nums[end-1];
            nums[end-1] = temp;
        }
        nums[left] = nums[begin-1];
        nums[begin-1] = key;
        quickSort(nums, left, begin-1);
        quickSort(nums, begin, right);
    }

    private boolean compare(int num1, int num2) {
        if (num1 == num2){
            return true;
        }
        if (num1 == 0){
            return false;
        }
        if (num2 == 0){
            return true;
        }
        if (num1 / num2 == 11){
            return true;
        }
        if (num2 / num1 == 11){
            return false;
        }
        Deque<Integer> nums1 = new ArrayDeque<>();
        Deque<Integer> nums2 = new ArrayDeque<>();
        int num1Temp = num1;
        int num2Temp = num2;
        while (num1Temp != 0){
            nums1.offerFirst(num1Temp % 10);
            num1Temp = num1Temp / 10;
        }
        while (num2Temp != 0){
            nums2.offerFirst(num2Temp % 10);
            num2Temp = num2Temp / 10;
        }
        while (true){
            int n1 = nums1.pollFirst();
            int n2 = nums2.pollFirst();
            if (n1 > n2){
                return true;
            }
            if (n1 < n2){
                return false;
            }
            nums1.offerLast(n1);
            nums2.offerLast(n2);
        }
    }
}
//leetcode submit region end(Prohibit modification and deletion)
