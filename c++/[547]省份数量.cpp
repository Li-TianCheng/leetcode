//
// 
// 有 n 个城市，其中一些彼此相连，另一些没有相连。如果城市 a 与城市 b 直接相连，且城市 b 与城市 c 直接相连，那么城市 a 与城市 c 间接相连
//。 
//
// 省份 是一组直接或间接相连的城市，组内不含其他没有相连的城市。 
//
// 给你一个 n x n 的矩阵 isConnected ，其中 isConnected[i][j] = 1 表示第 i 个城市和第 j 个城市直接相连，而 
//isConnected[i][j] = 0 表示二者不直接相连。 
//
// 返回矩阵中 省份 的数量。 
//
// 
//
// 示例 1： 
//
// 
//输入：isConnected = [[1,1,0],[1,1,0],[0,0,1]]
//输出：2
// 
//
// 示例 2： 
//
// 
//输入：isConnected = [[1,0,0],[0,1,0],[0,0,1]]
//输出：3
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 200 
// n == isConnected.length 
// n == isConnected[i].length 
// isConnected[i][j] 为 1 或 0 
// isConnected[i][i] == 1 
// isConnected[i][j] == isConnected[j][i] 
// 
// 
// 
// Related Topics 深度优先搜索 并查集 
// 👍 480 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> root(isConnected.size());
        unordered_set<int> result;
        for (int i = 0; i < isConnected.size(); i++){
            root[i] = i;
        }
        for (int i = 0; i < isConnected.size(); i++){
            for (int j = 0; j < isConnected.size(); j++){
                if (isConnected[i][j]){
                    merge(isConnected, root, i, j);
                }
            }
        }
        for (int i = 0; i < isConnected.size(); i++){
            result.insert(find(isConnected, root, i));
        }
        return result.size();
    }

private:
    int find(vector<vector<int>>& isConnected, vector<int>& root, int x){
        if (root[x] != x){
            root[x] = find(isConnected, root, root[x]);
        }
        return root[x];
    }

    void merge(vector<vector<int>>& isConnected, vector<int>& root, int x, int y){
        int rx = find(isConnected, root, x);
        int ry = find(isConnected, root, y);
        root[rx] = ry;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
