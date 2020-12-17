//给定一个无序的数组，找出数组在排序之后，相邻元素之间最大的差值。 
//
// 如果数组元素个数小于 2，则返回 0。 
//
// 示例 1: 
//
// 输入: [3,6,9,1]
//输出: 3
//解释: 排序后的数组是 [1,3,6,9], 其中相邻元素 (3,6) 和 (6,9) 之间都存在最大差值 3。 
//
// 示例 2: 
//
// 输入: [10]
//输出: 0
//解释: 数组元素个数小于 2，因此返回 0。 
//
// 说明: 
//
// 
// 你可以假设数组中所有元素都是非负整数，且数值在 32 位有符号整数范围内。 
// 请尝试在线性时间复杂度和空间复杂度的条件下解决此问题。 
// 
// Related Topics 排序 
// 👍 332 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2){
            return 0;
        }
        int result = 0;
        int maxValue = *max_element(nums.begin(), nums.end());
        int minValue = *min_element(nums.begin(), nums.end());
        int d = max(1, (maxValue - minValue)/((int)nums.size()-1));
        int bucketSize = (maxValue - minValue)/d+1;
        vector<vector<int>> bucket(bucketSize, vector<int>(2, -1));
        for (int i = 0; i < nums.size(); i++) {
            int idx = (nums[i] - minValue)/d;
            if (bucket[idx][0] == -1){
                bucket[idx][0] = bucket[idx][1] = nums[i];
            }else{
                bucket[idx][0] = min(bucket[idx][0], nums[i]);
                bucket[idx][1] = max(bucket[idx][1], nums[i]);
            }
        }
        int prev = -1;
        for (int i = 0; i < bucketSize; i++) {
            if (bucket[i][0] == -1){
                continue;
            }
            if (prev != -1){
                result = max(result, bucket[i][0]-bucket[prev][1]);
            }
            prev = i;
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
