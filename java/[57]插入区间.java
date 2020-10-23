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
// 👍 205 👎 0


import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    // method1
//    public int[][] insert(int[][] intervals, int[] newInterval) {
//        List<int[]> list = Arrays.asList(intervals);
//        List<int[]> arrList = new ArrayList<int[]>(list);
//        arrList.add(newInterval);
//        return merge(arrList.toArray(new int[arrList.size()][]));
//    }
//
//    private int[][] merge(int[][] intervals) {
//        List<int[]> result = new ArrayList<>();
//        Arrays.sort(intervals, (int[] intervals1, int[] intervals2) -> {return intervals1[0] - intervals2[0];});
//        for (int[] interval : intervals) {
//            if (result.size() == 0 || result.get(result.size() - 1)[1] < interval[0])
//                result.add(interval);
//            else
//                result.get(result.size() - 1)[1] = Math.max(result.get(result.size() - 1)[1], interval[1]);
//        }
//        return result.toArray(new int[result.size()][]);
//    }
    // method2
    public int[][] insert(int[][] intervals, int[] newInterval){
        if (intervals.length == 0)
            return new int[][]{newInterval};
        List<int[]> result = new ArrayList<>();
        int start = intervals.length;
        int end = -1;
        int left = 0;
        int right = intervals.length;
        while (left < right) {
            int mid = (left + right) / 2;
            if (newInterval[0] <= intervals[mid][1]){
                start = mid;
                right = mid;
            }else
                left = mid + 1;
        }
        left = 0;
        right = intervals.length;
        while (left < right) {
            int mid = (left + right) / 2;
            if (newInterval[1] >= intervals[mid][0]){
                end = mid;
                left = mid + 1;
            }else
                right = mid;
        }
        if (end == -1)
            result.add(newInterval);
        for (int i=0; i < start; i++)
            result.add(intervals[i]);
        if (end != -1 && start != intervals.length)
            result.add(new int[]{Math.min(intervals[start][0], newInterval[0]), Math.max(intervals[end][1], newInterval[1])});
        for (int i=end+1; i < intervals.length; i++)
            result.add(intervals[i]);
        if (start == intervals.length)
            result.add(newInterval);
        return result.toArray(new int[result.size()][]);
    }
}
//leetcode submit region end(Prohibit modification and deletion)
