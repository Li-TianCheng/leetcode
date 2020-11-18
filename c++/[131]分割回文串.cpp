//给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。 
//
// 返回 s 所有可能的分割方案。 
//
// 示例: 
//
// 输入: "aab"
//输出:
//[
//  ["aa","b"],
//  ["a","a","b"]
//] 
// Related Topics 回溯算法 
// 👍 424 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> temp;
        backtrack(s, result, temp);
        return result;
    }

    void backtrack(string s, vector<vector<string>>& result, vector<string>& temp){
        if (s.size() == 0){
            result.push_back(temp);
            return;
        }
        for (int i = 1; i <= s.size(); i++){
            if (!isValid(s.substr(0, i))){
                continue;
            }
            temp.push_back(s.substr(0, i));
            backtrack(s.substr(i), result, temp);
            temp.pop_back();
        }
    }

    bool isValid(string s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right){
            if (s[left] != s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
