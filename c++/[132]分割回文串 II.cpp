//给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。 
//
// 返回符合要求的最少分割次数。 
//
// 示例: 
//
// 输入: "aab"
//输出: 1
//解释: 进行一次分割就可将 s 分割成 ["aa","b"] 这样两个回文子串。
// 
// Related Topics 动态规划 
// 👍 223 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp;
        for (int i = 0; i < n; i++){
            dp.push_back(i);
        }
        for (int i = 1; i < n; i++){
            if (isValid(s, 0, i)){
                dp[i] = 0;
                continue;
            }
            for (int j = 0; j < i; j++){
                if (isValid(s, j+1, i)){
                    dp[i] = min(dp[i], dp[j]+1);
                }
            }
        }
        return dp[n-1];
    }

    bool isValid(string s, int left, int right){
        while(left < right){
            if(s[left] != s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
