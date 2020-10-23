//给定一个字符串 s1，我们可以把它递归地分割成两个非空子字符串，从而将其表示为二叉树。 
//
// 下图是字符串 s1 = "great" 的一种可能的表示形式。 
//
//     great
//   /    \
//  gr    eat
// / \    /  \
//g   r  e   at
//           / \
//          a   t
// 
//
// 在扰乱这个字符串的过程中，我们可以挑选任何一个非叶节点，然后交换它的两个子节点。 
//
// 例如，如果我们挑选非叶节点 "gr" ，交换它的两个子节点，将会产生扰乱字符串 "rgeat" 。 
//
//     rgeat
//   /    \
//  rg    eat
// / \    /  \
//r   g  e   at
//           / \
//          a   t
// 
//
// 我们将 "rgeat” 称作 "great" 的一个扰乱字符串。 
//
// 同样地，如果我们继续交换节点 "eat" 和 "at" 的子节点，将会产生另一个新的扰乱字符串 "rgtae" 。 
//
//     rgtae
//   /    \
//  rg    tae
// / \    /  \
//r   g  ta  e
//       / \
//      t   a
// 
//
// 我们将 "rgtae” 称作 "great" 的一个扰乱字符串。 
//
// 给出两个长度相等的字符串 s1 和 s2，判断 s2 是否是 s1 的扰乱字符串。 
//
// 示例 1: 
//
// 输入: s1 = "great", s2 = "rgeat"
//输出: true
// 
//
// 示例 2: 
//
// 输入: s1 = "abcde", s2 = "caebd"
//输出: false 
// Related Topics 字符串 动态规划 
// 👍 157 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size())
            return false;
        if (s1.size() == 1)
            return s1 == s2;
        unordered_map<char, int> map;
        for (int i = 0; i < s1.size(); i++){
            char c1 = s1[i];
            char c2 = s2[i];
            map[c1] = map[c1] + 1;
            map[c2] = map[c2] - 1;
        }
        for (auto & iter : map){
            if (iter.second != 0)
                return false;
        }
        for (int i = 1; i < s1.size(); i++){
            bool r1 = isScramble(s1.substr(0, i), s2.substr(0, i))
                      && isScramble(s1.substr(i), s2.substr(i));
            bool r2 = isScramble(s1.substr(0, i), s2.substr(s1.size()-i))
                      && isScramble(s1.substr(i), s2.substr(0, s1.size()-i));
            if (r1 || r2)
                return true;
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
