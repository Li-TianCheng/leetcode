//给你一个数组 nums ，请你完成两类查询，其中一类查询要求更新数组下标对应的值，另一类查询要求返回数组中某个范围内元素的总和。 
//
// 实现 NumArray 类： 
//
// 
// 
// 
// NumArray(int[] nums) 用整数数组 nums 初始化对象 
// void update(int index, int val) 将 nums[index] 的值更新为 val 
// int sumRange(int left, int right) 返回子数组 nums[left, right] 的总和（即，nums[left] + 
//nums[left + 1], ..., nums[right]） 
// 
//
// 
//
// 示例： 
//
// 
//输入：
//["NumArray", "sumRange", "update", "sumRange"]
//[[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
//输出：
//[null, 9, null, 8]
//
//解释：
//NumArray numArray = new NumArray([1, 3, 5]);
//numArray.sumRange(0, 2); // 返回 9 ，sum([1,3,5]) = 9
//numArray.update(1, 2);   // nums = [1,2,5]
//numArray.sumRange(0, 2); // 返回 8 ，sum([1,2,5]) = 9
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 3 * 104 
// -100 <= nums[i] <= 100 
// 0 <= index < nums.length 
// -100 <= val <= 100 
// 0 <= left <= right < nums.length 
// 最多调用 3 * 104 次 update 和 sumRange 方法 
// 
// 
// 
// Related Topics 树状数组 线段树 
// 👍 222 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class NumArray {
public:
    vector <int> heap;
    int n;
    NumArray(vector<int>& nums) {
        n = nums.size();
        heap = vector<int>(2*n);
        for (int i = n; i < 2*n; i++) {
            heap[i] = nums[i-n];
        }
        for (int i = n-1; i > 0; i--){
            heap[i] = heap[i*2] + heap[i*2+1];
        }
    }

    void update(int index, int val) {
        index += n;
        int temp = val - heap[index];
        while (index > 0){
            heap[index] += temp;
            index /= 2;
        }
    }

    int sumRange(int left, int right) {
        int sum = 0;
        left += n;
        right += n;
        while (left <= right){
            if (left % 2 == 1){
                sum += heap[left];
                left++;
            }
            if (right % 2 == 0){
                sum += heap[right];
                right--;
            }
            left /= 2;
            right /= 2;
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
//leetcode submit region end(Prohibit modification and deletion)
