//给出一个区间的集合，请合并所有重叠的区间。 
//
// 
//
// 示例 1: 
//
// 输入: intervals = [[1,3],[2,6],[8,10],[15,18]]
//输出: [[1,6],[8,10],[15,18]]
//解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
// 
//
// 示例 2: 
//
// 输入: intervals = [[1,4],[4,5]]
//输出: [[1,5]]
//解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。 
//
// 注意：输入类型已于2019年4月15日更改。 请重置默认代码定义以获取新方法签名。 
//
// 
//
// 提示： 
//
// 
// intervals[i][0] <= intervals[i][1] 
// 
// Related Topics 排序 数组 
// 👍 649 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        auto comp = [](const vector<int>& a, const vector<int>& b){return a[0] < b[0];};
        sort(intervals.begin(), intervals.end(), comp);
        for (vector<int> interval : intervals) {
            if (result.size() == 0 || result[result.size()-1][1] < interval[0])
                result.push_back(interval);
            else
                result[result.size()-1][1] = max(result[result.size()-1][1], interval[1]);
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
