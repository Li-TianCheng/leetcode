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
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // method1
//    bool isValidBST(TreeNode* root) {
//        stack<TreeNode*> stack;
//        long temp = INT64_MIN;
//        while (root != nullptr || !stack.empty()){
//            while (root != nullptr){
//                stack.push(root);
//                root = root->left;
//            }
//            root = stack.top();
//            stack.pop();
//            if (root->val <= temp){
//                return false;
//            }
//            temp = root->val;
//            root = root->right;
//        }
//        return true;
//    }
    //method2
    long prev = INT64_MIN;
    bool isValidBST(TreeNode* root) {
        return inorder(root);
    }

    bool inorder(TreeNode* node) {
        if (node == NULL){
            return true;
        }
        bool left = inorder(node->left);
        if (node->val <= prev){
            return false;
        }
        prev = node->val;
        bool right = inorder(node->right);
        return left && right;
    }
    //method3
//    bool isValidBST(TreeNode* root) {
//        return BFS(root, INT64_MIN, INT64_MAX);
//    }
//
//    bool BFS(TreeNode* root, long left, long right){
//        if (root == NULL){
//            return true;
//        }
//        if (root->val > left && root->val < right){
//            return BFS(root->left, left, root->val) && BFS(root->right, root->val, right);
//        }else{
//            return false;
//        }
//    }
};
//leetcode submit region end(Prohibit modification and deletion)
