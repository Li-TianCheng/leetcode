//实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。 
//
// 如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。 
//
// 必须原地修改，只允许使用额外常数空间。 
//
// 以下是一些例子，输入位于左侧列，其相应输出位于右侧列。 
//1,2,3 → 1,3,2 
//3,2,1 → 1,2,3 
//1,1,5 → 1,5,1 
// Related Topics 数组 
// 👍 678 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = nums.size() - 2;
        while (index >= 0 && nums[index] >= nums[index+1])
            index--;
        if (index >= 0) {
            int j = nums.size() - 1;
            while (j >= 0 && nums[j] <= nums[index])
                j--;
            swap(nums[index], nums[j]);
        }
        reverse(nums, index + 1);
    }

    void reverse(vector<int>& nums , int i){
        int j = nums.size() - 1;
        while (i < j){
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
