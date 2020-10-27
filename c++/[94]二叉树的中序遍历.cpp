//给定一个二叉树，返回它的中序 遍历。 
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
//输出: [1,3,2] 
//
// 进阶: 递归算法很简单，你可以通过迭代算法完成吗？ 
// Related Topics 栈 树 哈希表 
// 👍 757 👎 0


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
    // method1
//    vector<int> inorderTraversal(TreeNode* root) {
//        vector<int> result;
//        inorder(root, result);
//        return result;
//    }
//
//    void inorder(TreeNode* root, vector<int>& result) {
//        if (root == nullptr)
//            return;
//        inorder(root->left, result);
//        result.push_back(root->val);
//        inorder(root->right, result);
//    }
    //method2
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stack;
        vector<int> result;
        while (root != nullptr || !stack.empty()) {
            while (root != nullptr){
                stack.push(root);
                root = root->left;
            }
            root = stack.top();
            stack.pop();
            result.push_back(root->val);
            root = root->right;
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
