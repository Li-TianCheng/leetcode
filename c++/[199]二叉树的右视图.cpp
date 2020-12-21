//给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。 
//
// 示例: 
//
// 输入: [1,2,3,null,5,null,4]
//输出: [1, 3, 4]
//解释:
//
//   1            <---
// /   \
//2     3         <---
// \     \
//  5     4       <---
// 
// Related Topics 树 深度优先搜索 广度优先搜索 
// 👍 376 👎 0


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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> queue;
        if (root == nullptr){
            return result;
        }
        queue.push(root);
        while (!queue.empty()){
            int num = queue.size();
            for (int i = 0; i < num; i++){
                TreeNode* node = queue.front();
                queue.pop();
                if (i == num-1){
                    result.push_back(node->val);
                }
                if (node->left != nullptr){
                    queue.push(node->left);
                }
                if (node->right != nullptr){
                    queue.push(node->right);
                }
            }
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
