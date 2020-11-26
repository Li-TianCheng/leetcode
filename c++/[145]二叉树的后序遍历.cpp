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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> stack;
        TreeNode* prev;
        while (root != nullptr || !stack.empty()){
            while (root != nullptr){
                stack.push(root);
                root = root->left;
            }
            root = stack.top();
            stack.pop();
            if (root->right == nullptr || root->right == prev){
                result.push_back(root->val);
                prev = root;
                root = nullptr;
            }else{
                stack.push(root);
                root = root->right;
            }
        }
        return result;
    }

//    vector<int> postorderTraversal(TreeNode* root) {
//        vector<int> result;
//        helper(root, result);
//        return result;
//    }
//
//    void helper(TreeNode* node, vector<int>& result) {
//        if (node == nullptr){
//            return;
//        }
//        helper(node->left, result);
//        helper(node->right, result);
//        result.push_back(node->val);
//    }
};
//leetcode submit region end(Prohibit modification and deletion)
