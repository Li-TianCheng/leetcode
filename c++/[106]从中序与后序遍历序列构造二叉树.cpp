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
// 👍 395 👎 0


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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> map;
        for (int i = 0; i < inorder.size(); i++){
            map[inorder[i]] = i;
        }
        return buildHelper(map, postorder, postorder.size(), 0, inorder.size());
    }

    TreeNode* buildHelper(unordered_map<int, int>&map, vector<int>& postorder, int postorderRight, int inorderLeft, int inorderRight){
        if (inorderLeft >= inorderRight){
            return nullptr;
        }
        TreeNode* root = new TreeNode(postorder[postorderRight-1]);
        int index = map[postorder[postorderRight-1]];
        TreeNode* subTreeRight = buildHelper(map, postorder,
                                            postorderRight-1,
                                            index+1, inorderRight);
        TreeNode* subTreeLeft = buildHelper(map, postorder,
                                           postorderRight-(inorderRight-index),
                                           inorderLeft, index);
        root->left = subTreeLeft;
        root->right = subTreeRight;
        return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
