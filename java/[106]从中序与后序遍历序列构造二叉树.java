//根据一棵树的中序遍历与后序遍历构造二叉树。 
//
// 注意: 
//你可以假设树中没有重复的元素。 
//
// 例如，给出 
//
// 中序遍历 inorder = [9,3,15,20,7]
//后序遍历 postorder = [9,15,7,20,3] 
//
// 返回如下的二叉树： 
//
//     3
//   / \
//  9  20
//    /  \
//   15   7
// 
// Related Topics 树 深度优先搜索 数组 
// 👍 394 👎 0


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
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < inorder.length; i++) {
            map.put(inorder[i], i);
        }
        return buildHelper(map, postorder, postorder.length, 0, inorder.length);
    }

    private TreeNode buildHelper(HashMap<Integer, Integer> map, int[] postorder,
                                 int postorderRight, int inorderLeft, int inorderRight){
        if (inorderLeft >= inorderRight){
            return null;
        }
        TreeNode root = new TreeNode(postorder[postorderRight-1]);
        int index = map.get(postorder[postorderRight-1]);
        TreeNode subTreeRight = buildHelper(map, postorder,
                postorderRight-1,
                index+1, inorderRight);
        TreeNode subTreeLeft = buildHelper(map, postorder,
                postorderRight-(inorderRight-index),
                inorderLeft, index);
        root.left = subTreeLeft;
        root.right = subTreeRight;
        return root;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
