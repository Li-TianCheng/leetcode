//给定一组非负整数 nums，重新排列它们每个数字的顺序（每个数字不可拆分）使之组成一个最大的整数。 
//
// 注意：输出结果可能非常大，所以你需要返回一个字符串而不是整数。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [10,2]
//输出："210" 
//
// 示例 2： 
//
// 
//输入：nums = [3,30,34,5,9]
//输出："9534330"
// 
//
// 示例 3： 
//
// 
//输入：nums = [1]
//输出："1"
// 
//
// 示例 4： 
//
// 
//输入：nums = [10]
//输出："10"
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 100 
// 0 <= nums[i] <= 109 
// 
// Related Topics 排序 
// 👍 440 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string s;
        vector<string> str;
        for(int i=0;i<nums.size();++i)
            str.push_back(to_string(nums[i]));
        sort(str.begin(),str.end(),[](const string& a,const string& b){return a+b>b+a;});
        for(int i=0;i<nums.size();++i){
            s+=str[i];
        }
        return s[0] == '0' ? "0" : s;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
