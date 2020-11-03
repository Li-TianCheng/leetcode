//给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历） 
//
// 例如： 
//给定二叉树 [3,9,20,null,null,15,7], 
//
//     3
//   / \
//  9  20
//    /  \
//   15   7
// 
//
// 返回其自底向上的层次遍历为： 
//
// [
//  [15,7],
//  [9,20],
//  [3]
//]
// 
// Related Topics 树 广度优先搜索 
// 👍 358 👎 0


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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL){
            return result;
        }
        queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()) {
            int num = queue.size();
            vector<int> temp;
            for (int i = 0; i < num; ++i) {
                TreeNode* node = queue.front();
                queue.pop();
                temp.push_back(node->val);
                if (node->left != NULL){
                    queue.push(node->left);
                }
                if (node->right != NULL) {
                    queue.push(node->right);
                }
            }
            result.push_back(temp);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
