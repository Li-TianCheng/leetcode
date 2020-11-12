//给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。 
//
// 说明：本题中，我们将空字符串定义为有效的回文串。 
//
// 示例 1: 
//
// 输入: "A man, a plan, a canal: Panama"
//输出: true
// 
//
// 示例 2: 
//
// 输入: "race a car"
//输出: false
// 
// Related Topics 双指针 字符串 
// 👍 292 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            if (!isValid(s[left])) {
                left++;
                continue;
            }
            if (!isValid(s[right])){
                right--;
                continue;
            }
            if (helper(s[left]) != helper(s[right])){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    char helper(char c) {
        if (c >= 'A' && c <= 'Z'){
            c = (char)((int)c - 'A' + 'a');
        }
        return c;
    }

    bool isValid(char c) {
        if (c >= 'A' && c <= 'Z'){
            return true;
        }else if (c >= '0' && c <= '9'){
            return true;
        }else {
            return c >= 'a' && c <= 'z';
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
