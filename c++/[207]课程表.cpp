//你这个学期必须选修 numCourse 门课程，记为 0 到 numCourse-1 。 
//
// 在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们：[0,1] 
//
// 给定课程总量以及它们的先决条件，请你判断是否可能完成所有课程的学习？ 
//
// 
//
// 示例 1: 
//
// 输入: 2, [[1,0]] 
//输出: true
//解释: 总共有 2 门课程。学习课程 1 之前，你需要完成课程 0。所以这是可能的。 
//
// 示例 2: 
//
// 输入: 2, [[1,0],[0,1]]
//输出: false
//解释: 总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0；并且学习课程 0 之前，你还应先完成课程 1。这是不可能的。 
//
// 
//
// 提示： 
//
// 
// 输入的先决条件是由 边缘列表 表示的图形，而不是 邻接矩阵 。详情请参见图的表示法。 
// 你可以假定输入的先决条件中没有重复的边。 
// 1 <= numCourses <= 10^5 
// 
// Related Topics 深度优先搜索 广度优先搜索 图 拓扑排序 
// 👍 686 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        for (vector<int> prerequisite : prerequisites){
            adjList[prerequisite[0]].push_back(prerequisite[1]);
        }
        vector<int> visited(numCourses, 0);
        for (int i = 0; i < numCourses; i++){
            if (visited[i] == -1){
                continue;
            }
            visited[i] = 1;
            if (!helper(i, adjList, visited)){
                return false;
            }
            visited[i] = -1;
        }
        return true;
    }

private:
    bool helper(int index, const vector<vector<int>>& adjList, vector<int>& visited){
        for (int adj : adjList[index]){
            if (visited[adj] == 1){
                return false;
            }
            visited[adj] = 1;
            if (!helper(adj, adjList, visited)){
                return false;
            }
            visited[adj] = -1;
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
