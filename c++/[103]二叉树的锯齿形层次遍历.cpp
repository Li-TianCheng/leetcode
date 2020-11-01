//给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。 
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
// 返回锯齿形层次遍历如下： 
//
// [
//  [3],
//  [20,9],
//  [15,7]
//]
// 
// Related Topics 栈 树 广度优先搜索 
// 👍 285 👎 0


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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr){
            return result;
        }
        queue<TreeNode*> queue;
        int deep = 0;
        queue.push(root);
        while (!queue.empty()){
            int num = queue.size();
            vector<int> temp;
            for (int i = 0; i < num; i++){
                TreeNode* node = queue.front();
                queue.pop();
                temp.push_back(node->val);
                if (node->left != nullptr){
                    queue.push(node->left);
                }
                if (node->right != nullptr){
                    queue.push(node->right);
                }
            }
            if (deep % 2 == 1){
                reverse(temp.begin(), temp.end());
            }
            result.push_back(temp);
            deep++;
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
