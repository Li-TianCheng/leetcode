//给定一个二维平面，平面上有 n 个点，求最多有多少个点在同一条直线上。 
//
// 示例 1: 
//
// 输入: [[1,1],[2,2],[3,3]]
//输出: 3
//解释:
//^
//|
//|        o
//|     o
//|  o  
//+------------->
//0  1  2  3  4
// 
//
// 示例 2: 
//
// 输入: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
//输出: 4
//解释:
//^
//|
//|  o
//|     o        o
//|        o
//|  o        o
//+------------------->
//0  1  2  3  4  5  6 
// Related Topics 哈希表 数学 
// 👍 200 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int len = points.size();
        if (len <= 2){
            return len;
        }
        int ans = 0;
        for (int i = 0; i < len; i++) {
            if (len - i <= ans) {
                break;
            }
            int repeat = 1 ;
            int curMax = 1;
            for (int j = i + 1 ; j < len; j++) {
                if (len - j + curMax <= ans) {
                    break;
                }
                curMax++;
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                if (x1 == x2 && y1 == y2) {
                    repeat++;
                    ans = max(ans, curMax);
                    continue;
                }
                for (int k = j + 1; k < len; k++) {
                    if(len - k + curMax <= ans) {
                        break;
                    }
                    int x3 = points[k][0];
                    int y3 = points[k][1];
                    if ((long)(y2 - y1) * (x3 - x2) == (long)(y3 - y2) * (x2 - x1)) {
                        curMax++;
                    }
                }
                ans = max(ans, curMax);
                curMax = repeat;
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
