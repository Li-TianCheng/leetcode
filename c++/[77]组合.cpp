//给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。 
//
// 示例: 
//
// 输入: n = 4, k = 2
//输出:
//[
//  [2,4],
//  [3,4],
//  [2,3],
//  [1,2],
//  [1,3],
//  [1,4],
//] 
// Related Topics 回溯算法 
// 👍 416 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> result;

    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        backtrack(n, k, temp, 1);
        return result;
    }

    void backtrack(int& n, int& k, vector<int>& temp, int start){
        if (temp.size() == k){
            result.push_back(temp);
            return;
        }
        for (int i = start; i <= n; i++){
            temp.push_back(i);
            backtrack(n, k, temp, i+1);
            temp.pop_back();
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
