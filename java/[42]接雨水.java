//给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。 
//
// 
//
// 上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢 Mar
//cos 贡献此图。 
//
// 示例: 
//
// 输入: [0,1,0,2,1,0,1,3,2,1,2,1]
//输出: 6 
// Related Topics 栈 数组 双指针 
// 👍 1583 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
//    public int trap(int[] height) {
//        /**
//        * @MethodName: trap method1
//        * @Description: stack
//        * @Param: [height]
//        * @return: int
//        * @Author: Ltc
//        * @Date: 2020/8/25 10:01
//        **/
//        Stack<Integer> stack = new Stack<>();
//        int result = 0;
//        int idx = 0;
//        while (idx < height.length){
//            while (!stack.empty() && height[idx] > height[stack.peek()]){
//                int top = stack.pop();
//                if (stack.empty())
//                    break;
//                result = result + (Math.min(height[idx], height[stack.peek()]) - height[top]) * (idx - stack.peek() - 1);
//            }
//            stack.push(idx);
//            idx++;
//        }
//        return result;
//    }

    public int trap(int[] height) {
        /**
        * @MethodName: trap method2
        * @Description: double pointer
        * @Param: [height]
        * @return: int
        * @Author: Ltc
        * @Date: 2020/8/25 10:01
        **/
        int left = 0;
        int right = height.length - 1;
        int result = 0;
        int leftMax = 0;
        int rightMax = 0;
        while (left < right){
            if (height[left] < height[right]){
                if (height[left] > leftMax){
                    leftMax = height[left];
                }else {
                    result = result + leftMax - height[left];
                }
                left++;
            }else {
                if (height[right] > rightMax){
                    rightMax = height[right];
                }else {
                    result = result + rightMax - height[right];
                }
                right--;
            }
        }
        return result;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
