//给定一个整数数组 nums，按要求返回一个新数组 counts。数组 counts 有该性质： counts[i] 的值是 nums[i] 右侧小于 num
//s[i] 的元素的数量。 
//
// 
//
// 示例： 
//
// 输入：nums = [5,2,6,1]
//输出：[2,1,1,0] 
//解释：
//5 的右侧有 2 个更小的元素 (2 和 1)
//2 的右侧仅有 1 个更小的元素 (1)
//6 的右侧有 1 个更小的元素 (1)
//1 的右侧有 0 个更小的元素
// 
//
// 
//
// 提示： 
//
// 
// 0 <= nums.length <= 10^5 
// -10^4 <= nums[i] <= 10^4 
// 
// Related Topics 排序 树状数组 线段树 二分查找 分治算法 
// 👍 524 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    int[] index;
    int[] result;
    int[] temp;
    int[] tempIndex;
    public List<Integer> countSmaller(int[] nums) {
        index = new int[nums.length];
        result = new int[nums.length];
        temp = new int[nums.length];
        tempIndex = new int[nums.length];
        for (int i = 0; i < nums.length; i++){
            index[i] = i;
            tempIndex[i] = i;
            temp[i] = nums[i];
        }
        mergeSort(nums, 0, nums.length);
        List<Integer> ans = new ArrayList<>();
        for (int it : result){
            ans.add(it);
        }
        return ans;
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

    public void merge(int[] nums, int x, int mid, int y){
        int idx = y-1;
        int left = mid-1;
        int right = y-1;
        while (left >= x || right >= mid){
            int tempLeft = left >= x ? nums[left] : Integer.MIN_VALUE;
            int tempRight = right >= mid ? nums[right] : Integer.MIN_VALUE;
            if (tempLeft > tempRight){
                result[index[left]] += right - mid + 1;
                tempIndex[idx] = index[left];
                temp[idx] = nums[left];
                left--;
            }else{
                tempIndex[idx] = index[right];
                temp[idx] = nums[right];
                right--;
            }
            idx--;
        }
        for (int i = x; i < y; i++){
            index[i] = tempIndex[i];
            nums[i] = temp[i];
        }
    }
}
//leetcode submit region end(Prohibit modification and deletion)
