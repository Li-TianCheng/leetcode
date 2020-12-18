//所有 DNA 都由一系列缩写为 'A'，'C'，'G' 和 'T' 的核苷酸组成，例如："ACGAATTCCG"。在研究 DNA 时，识别 DNA 中的重复
//序列有时会对研究非常有帮助。 
//
// 编写一个函数来找出所有目标子串，目标子串的长度为 10，且在 DNA 字符串 s 中出现次数超过一次。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
//输出：["AAAAACCCCC","CCCCCAAAAA"]
// 
//
// 示例 2： 
//
// 
//输入：s = "AAAAAAAAAAAAA"
//输出：["AAAAAAAAAA"]
// 
//
// 
//
// 提示： 
//
// 
// 0 <= s.length <= 105 
// s[i] 为 'A'、'C'、'G' 或 'T' 
// 
// Related Topics 位运算 哈希表 
// 👍 130 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() < 10){
            return vector<string>();
        }
        vector<string> result;
        unordered_map<string, int> map;
        for (int i = 0; i <= s.size()-10; i++){
            string substr = s.substr(i, 10);
            map[substr]++;
        }
        for (auto& p : map){
            if (p.second > 1){
                result.push_back(p.first);
            }
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
