//给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。 
//
// 
//
// 在杨辉三角中，每个数是它左上方和右上方的数的和。 
//
// 示例: 
//
// 输入: 5
//输出:
//[
//     [1],
//    [1,1],
//   [1,2,1],
//  [1,3,3,1],
// [1,4,6,4,1]
//] 
// Related Topics 数组 
// 👍 372 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> result = new ArrayList<>();
        for (int i = 0; i < numRows; i++) {
            List<Integer> temp = new ArrayList<>();
            if (i == 0) {
                temp.add(1);
            }else{
                for (int j = 0; j < i; j++) {
                    int num1 = j-1 < 0 ? 0 : result.get(i-1).get(j-1);
                    int num2 = result.get(i-1).get(j);
                    temp.add(num1 + num2);
                }
                temp.add(1);
            }
            result.add(new ArrayList<>(temp));
        }
        return result;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
