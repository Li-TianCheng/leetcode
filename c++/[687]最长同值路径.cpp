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
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        int result = 0;
        help(root, result);
        return result;
    }

    int help(TreeNode* node, int& result){
        if (node == nullptr){
            return 0;
        }
        int left = help(node->left, result);
        int right = help(node->right, result);
        int reLeft = 0;
        int reRight = 0;
        if (node->left != nullptr && node->left->val == node->val) {
            reLeft += left + 1;
        }
        if (node->right != nullptr && node->right->val == node->val) {
            reRight += right + 1;
        }
        result = max(result, reLeft+reRight);
        return max(reLeft, reRight);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
