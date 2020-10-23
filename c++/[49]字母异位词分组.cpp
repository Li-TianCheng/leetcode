//给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。 
//
// 示例: 
//
// 输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
//输出:
//[
//  ["ate","eat","tea"],
//  ["nat","tan"],
//  ["bat"]
//] 
//
// 说明： 
//
// 
// 所有输入均为小写字母。 
// 不考虑答案输出的顺序。 
// 
// Related Topics 哈希表 字符串 
// 👍 484 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        if (strs.empty())
            return result;
        unordered_map<string, vector<string>> map;
        for (string s : strs){
            int count[26] = {0};
            for (char c : s)
                count[c-'a']++;
            string key;
            for (int i = 0; i < 26; i++){
                key += '#';
                key += count[i];
            }
            if (map.find(key) == map.end()){
                vector<string> init;
                map[key] = init;
            }
            map[key].push_back(s);
        }
        auto iter = map.begin();
        for (auto iter = map.begin(); iter != map.end(); iter++)
            result.push_back(iter->second);
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
