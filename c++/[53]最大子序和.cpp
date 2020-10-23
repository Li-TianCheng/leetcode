//给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。 
//
// 示例: 
//
// 输入: [-2,1,-3,4,-1,2,1,-5,4]
//输出: 6
//解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
// 
//
// 进阶: 
//
// 如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。 
// Related Topics 数组 分治算法 动态规划 
// 👍 2519 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // method1
//    int maxSubArray(vector<int>& nums) {
//        int pre = 0;
//        int result = nums[0];
//        for (int i : nums){
//            pre = max(pre+i, i);
//            result = max(pre, result);
//        }
//        return result;
//    }

    // method2
    struct Status{
        int lSum;
        int rSum;
        int iSum;
        int mSum;
    };

    int maxSubArray(vector<int>& nums){
        int l = 0;
        int r = nums.size() - 1;
        return getInfo(nums, l, r).mSum;
    }

    Status getInfo(vector<int>& a, int l, int r){
        if (l == r)
            return Status{a[l], a[l], a[l], a[l]};
        int m = (l + r) >> 1;
        Status&& lSub = getInfo(a , l, m);
        m = m + 1;
        Status&& rSub = getInfo(a , m, r);
        return pushUp(lSub, rSub);
    }

    Status pushUp(Status& l, Status& r){
        int iSum = l.iSum + r.iSum;
        int lSum = max(l.lSum, l.iSum+r.lSum);
        int rSum = max(r.rSum, r.iSum+l.rSum);
        int mSum = max(max(l.mSum, r.mSum), l.rSum+r.lSum);
        return Status{lSum, rSum, iSum, mSum};
    }
};
//leetcode submit region end(Prohibit modification and deletion)
