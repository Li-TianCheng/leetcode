//给定一个二叉树，判断其是否是一个有效的二叉搜索树。 
//
// 假设一个二叉搜索树具有如下特征： 
//
// 
// 节点的左子树只包含小于当前节点的数。 
// 节点的右子树只包含大于当前节点的数。 
// 所有左子树和右子树自身必须也是二叉搜索树。 
// 
//
// 示例 1: 
//
// 输入:
//    2
//   / \
//  1   3
//输出: true
// 
//
// 示例 2: 
//
// 输入:
//    5
//   / \
//  1   4
//     / \
//    3   6
//输出: false
//解释: 输入为: [5,1,4,null,null,3,6]。
//     根节点的值为 5 ，但是其右子节点值为 4 。
// 
// Related Topics 树 深度优先搜索 
// 👍 817 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    // method1
//    public boolean isValidBST(TreeNode root) {
//        Stack<TreeNode> stack = new Stack<>();
//        long temp = Long.MIN_VALUE;
//        while (root != null || !stack.isEmpty()) {
//            while (root != null){
//                stack.push(root);
//                root = root.left;
//            }
//            root = stack.pop();
//            if (root.val <= temp){
//                return false;
//            }
//            temp = root.val;
//            root = root.right;
//        }
//        return true;
//    }
    //method2
    long pre = Long.MIN_VALUE;
    public boolean isValidBST(TreeNode root) {
        return inorder(root);
    }
    private boolean inorder(TreeNode node) {
        if(node == null) {
            return true;
        }
        boolean left = inorder(node.left);
        if(node.val <= pre) {
            return false;
        }
        pre = node.val;
        boolean right = inorder(node.right);
        return left && right;
    }
    //method3
//    public boolean isValidBST(TreeNode root) {
//        return BFS(root, Long.MIN_VALUE, Long.MAX_VALUE);
//    }
//
//    private boolean BFS(TreeNode Node, long left, long right){
//        if (Node == null){
//            return true;
//        }
//        if (left < Node.val && right > Node.val){
//            return BFS(Node.left, left, Node.val) && BFS(Node.right, Node.val, right);
//        }else
//            return false;
//    }
}
//leetcode submit region end(Prohibit modification and deletion)
