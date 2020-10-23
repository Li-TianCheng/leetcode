//验证给定的字符串是否可以解释为十进制数字。 
//
// 例如: 
//
// "0" => true 
//" 0.1 " => true 
//"abc" => false 
//"1 a" => false 
//"2e10" => true 
//" -90e3 " => true 
//" 1e" => false 
//"e3" => false 
//" 6e-1" => true 
//" 99e2.5 " => false 
//"53.5e93" => true 
//" --6 " => false 
//"-+3" => false 
//"95a54e53" => false 
//
// 说明: 我们有意将问题陈述地比较模糊。在实现代码之前，你应当事先思考所有可能的情况。这里给出一份可能存在于有效十进制数字中的字符列表： 
//
// 
// 数字 0-9 
// 指数 - "e" 
// 正/负号 - "+"/"-" 
// 小数点 - "." 
// 
//
// 当然，在输入中，这些字符的上下文也很重要。 
//
// 更新于 2015-02-10: 
//C++函数的形式已经更新了。如果你仍然看见你的函数接收 const char * 类型的参数，请点击重载按钮重置你的代码。 
// Related Topics 数学 字符串 
// 👍 157 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Automaton {
public:
    static int stateTranslate(const int& state, const char& c){
        switch (state) {
            case 0:
            {
                if (c == '+' || c == '-') return 1;
                else if (c >= '0' && c <= '9') return 2;
                else if (c == '.') return 3;
                else return 7;
            }
            case 1:
            {
                if (c >= '0' && c <= '9') return 2;
                else if (c == '.') return 3;
                else return 7;
            }
            case 2:
            {
                if (c >= '0' && c <= '9') return 2;
                else if (c == '.') return 4;
                else if (c == 'e') return 5;
                else return 7;
            }
            case 3:
            {
                if (c >= '0' && c <= '9') return 4;
                else return 7;
            }
            case 4:
            {
                if (c >= '0' && c <= '9') return 4;
                else if (c == 'e') return 5;
                else return 7;
            }
            case 5:
            {
                if (c >= '0' && c <= '9') return 5;
                else if (c == '+' || c == '-') return 6;
                else return 7;
            }
            case 6:
            {
                if (c >= '0' && c <= '9') return 6;
                else return 7;
            }
            default: return 7;
        }
    }

    static bool automatonOutput(const int& state, const char& c){
        switch (state){
            case 0: return false;
            case 7: return false;
            case 3: return false;
            case 1: return false;
            case 4: return true;
            default:
            {
                if (c >= '0' && c <= '9') return true;
                else return false;
            }
        }
    }
};


class Solution {
public:
    bool isNumber(string s) {
        s.erase(0, s.find_first_not_of(' '));
        s.erase(s.find_last_not_of(' ')+1);
        if (s.empty())
            return false;
        int state = 0;
        for (char & i : s){
            if (state == 7)
                break;
            state = Automaton::stateTranslate(state, i);
        }
        return Automaton::automatonOutput(state, s[s.size()-1]);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
