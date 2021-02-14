//给定一个二叉树，找到最长的路径，这个路径中的每个节点具有相同值。 这条路径可以经过也可以不经过根节点。 
//
// 注意：两个节点之间的路径长度由它们之间的边数表示。 
//
// 示例 1: 
//
// 输入: 
//
// 
//              5
//             / \
//            4   5
//           / \   \
//          1   1   5
// 
//
// 输出: 
//
// 
//2
// 
//
// 示例 2: 
//
// 输入: 
//
// 
//              1
//             / \
//            4   5
//           / \   \
//          4   4   5
// 
//
// 输出: 
//
// 
//2
// 
//
// 注意: 给定的二叉树不超过10000个结点。 树的高度不超过1000。 
// Related Topics 树 递归 
// 👍 423 👎 0


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
    int result = 0;
    public int longestUnivaluePath(TreeNode root) {
        help(root);
        return result;
    }

    private int help(TreeNode node) {
        if (node == null){
            return 0;
        }
        int left = help(node.left);
        int right = help(node.right);
        int reLeft = 0;
        int reRight = 0;
        if (node.left != null && node.left.val == node.val){
            reLeft += left + 1;
        }
        if (node.right != null && node.right.val == node.val){
            reRight += right + 1;
        }
        result = Math.max(result, reLeft+reRight);
        return Math.max(reLeft, reRight);
    }
}
//leetcode submit region end(Prohibit modification and deletion)
