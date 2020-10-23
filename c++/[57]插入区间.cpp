//给出一个无重叠的 ，按照区间起始端点排序的区间列表。 
//
// 在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。 
//
// 
//
// 示例 1： 
//
// 输入：intervals = [[1,3],[6,9]], newInterval = [2,5]
//输出：[[1,5],[6,9]]
// 
//
// 示例 2： 
//
// 输入：intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
//输出：[[1,2],[3,10],[12,16]]
//解释：这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠。
// 
//
// 
//
// 注意：输入类型已在 2019 年 4 月 15 日更改。请重置为默认代码定义以获取新的方法签名。 
// Related Topics 排序 数组 
// 👍 211 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // method1
//    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
//        intervals.push_back(newInterval);
//        return merge(intervals);
//    }
//
//    vector<vector<int>> merge(vector<vector<int>>& intervals) {
//        vector<vector<int>> result;
//        auto comp = [](const vector<int>& a, const vector<int>& b){return a[0] < b[0];};
//        sort(intervals.begin(), intervals.end(), comp);
//        for (vector<int> interval : intervals) {
//            if (result.size() == 0 || result[result.size()-1][1] < interval[0])
//                result.push_back(interval);
//            else
//                result[result.size()-1][1] = max(result[result.size()-1][1], interval[1]);
//        }
//        return result;
//    }

    // method2
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval){
        if (intervals.size() == 0)
            return vector<vector<int>>{newInterval};
        vector<vector<int>> result;
        int start = intervals.size();
        int end = -1;
        int left = 0;
        int right = intervals.size();
        while (left < right){
            int mid = (left + right) >> 1;
            if (newInterval[0] <= intervals[mid][1]){
                start = mid;
                right = mid;
            }else
                left = mid + 1;
        }
        left = 0;
        right = intervals.size();
        while (left < right){
            int mid = (left + right) >> 1;
            if (newInterval[1] >= intervals[mid][0]){
                end = mid;
                left = mid + 1;
            }else
                right = mid;
        }
        if (end == -1)
            result.push_back(newInterval);
        for (int i = 0; i < start; i++)
            result.push_back(intervals[i]);
        if (end != -1 && start != intervals.size())
            result.push_back(vector<int>{min(intervals[start][0], newInterval[0]), max(intervals[end][1], newInterval[1])});
        for (int i = end+1; i < intervals.size(); i++)
            result.push_back(intervals[i]);
        if (start == intervals.size())
            result.push_back(newInterval);
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
