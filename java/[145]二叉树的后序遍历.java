//给定一个二叉树，返回它的 后序 遍历。 
//
// 示例: 
//
// 输入: [1,null,2,3]  
//   1
//    \
//     2
//    /
//   3 
//
//输出: [3,2,1] 
//
// 进阶: 递归算法很简单，你可以通过迭代算法完成吗？ 
// Related Topics 栈 树 
// 👍 481 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
//    public List<Integer> postorderTraversal(TreeNode root) {
//        List<Integer> result = new ArrayList<>();
//        TreeNode node = root;
//        Stack<TreeNode> stack = new Stack<>();
//        TreeNode prev = null;
//        while (node != null || !stack.isEmpty()) {
//            while (node != null){
//                stack.push(node);
//                node = node.left;
//            }
//            node = stack.pop();
//            if (node.right == null || node.right == prev) {
//                result.add(node.val);
//                prev = node;
//                node = null;
//            }else{
//                stack.push(node);
//                node = node.right;
//            }
//        }
//        return result;
//    }

    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        helper(root, result);
        return result;
    }

    private void helper(TreeNode node, List<Integer> result){
        if (node == null){
            return;
        }
        helper(node.left, result);
        helper(node.right, result);
        result.add(node.val);
    }
}
//leetcode submit region end(Prohibit modification and deletion)
