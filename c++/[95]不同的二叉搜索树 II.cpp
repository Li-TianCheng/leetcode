//给定一个整数 n，生成所有由 1 ... n 为节点所组成的 二叉搜索树 。 
//
// 
//
// 示例： 
//
// 输入：3
//输出：
//[
//  [1,null,3,2],
//  [3,2,null,1],
//  [3,1,null,null,2],
//  [2,1,3],
//  [1,null,2,null,3]
//]
//解释：
//以上的输出对应以下 5 种不同结构的二叉搜索树：
//
//   1         3     3      2      1
//    \       /     /      / \      \
//     3     2     1      1   3      2
//    /     /       \                 \
//   2     1         2                 3
// 
//
// 
//
// 提示： 
//
// 
// 0 <= n <= 8 
// 
// Related Topics 树 动态规划 
// 👍 684 👎 0


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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0)
            return vector<TreeNode*>();
        vector<TreeNode*> result = generate(1, n);
        return result;
    }

    vector<TreeNode*> generate(int start, int end){
        vector<TreeNode*> result;
        if (start > end){
            result.push_back(NULL);
            return result;
        }
        for (int i = start; i <= end; i++){
            vector<TreeNode*> leftGenerate = generate(start, i-1);
            vector<TreeNode*> rightGenerate = generate(i+1, end);
            for (TreeNode* left : leftGenerate){
                for (TreeNode* right : rightGenerate){
                    TreeNode* newRoot = new TreeNode(i, left, right);
                    result.push_back(newRoot);
                }
            }
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
