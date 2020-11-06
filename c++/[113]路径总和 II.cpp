//给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。 
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
//         /  \    / \
//        7    2  5   1
// 
//
// 返回: 
//
// [
//   [5,4,11,2],
//   [5,8,4,5]
//]
// 
// Related Topics 树 深度优先搜索 
// 👍 379 👎 0


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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int> temp;
        if (root == nullptr){
            return result;
        }
        DFS(root, sum, 0, result, temp);
        return result;
    }

    void DFS(TreeNode* node, int sum, int curr, vector<vector<int>>& result, vector<int>& temp) {
        if (node == nullptr){
            if (curr == sum){
                result.push_back(temp);
            }
            return;
        }
        curr += node->val;
        temp.push_back(node->val);
        if (node->left == nullptr){
            DFS(node->right, sum, curr, result, temp);
        }else if (node->right == nullptr){
            DFS(node->left, sum, curr, result, temp);
        }else{
            DFS(node->left, sum, curr, result, temp);
            DFS(node->right, sum, curr, result, temp);
        }
        temp.pop_back();
    }
};
//leetcode submit region end(Prohibit modification and deletion)
