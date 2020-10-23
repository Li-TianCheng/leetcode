//给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列。 
//
// 按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下： 
//
// 
// "123" 
// "132" 
// "213" 
// "231" 
// "312" 
// "321" 
// 
//
// 给定 n 和 k，返回第 k 个排列。 
//
// 说明： 
//
// 
// 给定 n 的范围是 [1, 9]。 
// 给定 k 的范围是[1, n!]。 
// 
//
// 示例 1: 
//
// 输入: n = 3, k = 3
//输出: "213"
// 
//
// 示例 2: 
//
// 输入: n = 4, k = 9
//输出: "2314"
// 
// Related Topics 数学 回溯算法 
// 👍 403 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public String getPermutation(int n, int k) {
        List<Integer> set = new ArrayList<Integer>();
        for (int i = 0; i < n; i++){
            set.add(i+1);
        }
        StringBuffer result = new StringBuffer();
        while (!set.isEmpty()){
            int t = (k - 1) / factorial(n - 1);
            result.append(set.get(t));
            set.remove(t);
            k -= t * factorial(n - 1);
            n--;
        }
        return result.toString();
    }

    public int factorial(int number) {
        if (number <= 1)
            return 1;
        else
            return number * factorial(number - 1);
    }
}
//leetcode submit region end(Prohibit modification and deletion)
