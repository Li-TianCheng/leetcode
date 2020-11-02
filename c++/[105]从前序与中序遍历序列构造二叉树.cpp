//根据一棵树的前序遍历与中序遍历构造二叉树。 
//
// 注意: 
//你可以假设树中没有重复的元素。 
//
// 例如，给出 
//
// 前序遍历 preorder = [3,9,20,15,7]
//中序遍历 inorder = [9,3,15,20,7] 
//
// 返回如下的二叉树： 
//
//     3
//   / \
//  9  20
//    /  \
//   15   7 
// Related Topics 树 深度优先搜索 数组 
// 👍 737 👎 0


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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> map;
        for (int i = 0; i < inorder.size(); i++){
            map[inorder[i]] = i;
        }
        return buildHelper(map, preorder, 0, 0, inorder.size());
    }

    TreeNode* buildHelper(unordered_map<int, int>& map, vector<int>& preorder, int preorderLeft, int inorderLeft, int inorderRight){
        if (inorderLeft >= inorderRight){
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[preorderLeft]);
        int index = map[preorder[preorderLeft]];
        TreeNode* subTreeLeft = buildHelper(map, preorder,
                                           preorderLeft+1,
                                           inorderLeft, index);
        TreeNode* subTreeRight = buildHelper(map, preorder,
                                            preorderLeft+index-inorderLeft+1,
                                            index+1, inorderRight);
        root->left = subTreeLeft;
        root->right = subTreeRight;
        return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
