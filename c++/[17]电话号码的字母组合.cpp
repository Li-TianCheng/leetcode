//给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。 
//
// 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。 
//
// 
//
// 示例: 
//
// 输入："23"
//输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
// 
//
// 说明: 
//尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。 
// Related Topics 字符串 回溯算法 
// 👍 935 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    map<string, string> letters = {
            {"2", "abc"},
            {"3", "def"},
            {"4", "ghi"},
            {"5", "jkl"},
            {"6", "mno"},
            {"7", "pqrs"},
            {"8", "tuv"},
            {"9", "wxyz"},
    };
    vector<string> result;

    vector<string> letterCombinations(string digits) {
        // DFS
        if (!digits.empty())
            backtrack(digits, "");
        return result;
        // BFS
//        if (!digits.empty()){
//            string sub_digit1 = digits.substr(0, 1);
//            string sub_digit2 = digits.substr(1);
//            map<string, string>::iterator iter;
//            iter = letters.find(sub_digit1);
//            string letter = iter->second;
//            for (int i = 0; i < letter.size(); i++){
//                result.push_back(letter.substr(i, 1));
//            }
//            backtrack(sub_digit2);
//        }
//        return result;
    }

private:
    // DFS
    void backtrack(const string& digits, const string& com){
        if (digits.empty()){
            result.push_back(com);
            return;
        }
        string sub_digit1 = digits.substr(0, 1);
        string sub_digit2 = digits.substr(1);
        map<string, string>::iterator iter;
        iter = letters.find(sub_digit1);
        string letter = iter->second;
        for (int i = 0; i < letter.size(); i++){
            string temp = letter.substr(i, 1);
            backtrack(sub_digit2, com+temp);
        }
    }
    // BFS
//    void backtrack(string digits){
//        if (digits.empty()) return;
//        string sub_digit1 = digits.substr(0, 1);
//        string sub_digit2 = digits.substr(1);
//        map<string, string>::iterator iter;
//        iter = letters.find(sub_digit1);
//        string letter = iter->second;
//        vector<string> temp_res;
//        for (int i = 0; i < letter.size(); i++){
//            string temp = letter.substr(i, 1);
//            for (auto & j : result){
//                temp_res.push_back(j + temp);
//            }
//        }
//        result = temp_res;
//        backtrack(sub_digit2);
//    }
};
//leetcode submit region end(Prohibit modification and deletion)
