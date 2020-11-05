//给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。 
//
// 说明: 叶子节点是指没有子节点的节点。 
//
// 示例: 
//给定如下二叉树，以及目标和 sum = 22， 
//
//               5
//             / \
//            4   8
//           /   / \
//          11  13  4
//         /  \      \
//        7    2      1
// 
//
// 返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2。 
// Related Topics 树 深度优先搜索 
// 👍 455 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr){
            return false;
        }
        return DFS(root, 0, sum);
    }

    bool DFS(TreeNode* node, int result, int sum){
        if (node == nullptr){
            return result == sum;
        }
        if (node->left == nullptr){
            return DFS(node->right, result+node->val, sum);
        }else if (node->right == nullptr){
            return DFS(node->left, result+node->val, sum);
        }else{
            return DFS(node->left, result+node->val, sum) || DFS(node->right, result+node->val, sum);
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
