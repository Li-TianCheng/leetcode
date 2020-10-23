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
// 👍 153 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public boolean isNumber(String s) {
        s = s.trim();
        if (s.length() == 0)
            return false;
        String state = "start";
        Automaton automaton = new Automaton();
        for (int i =0; i < s.length(); i++) {
            if (state == "end")
                break;
            state = automaton.stateTarnslate(state, s.charAt(i));
        }
        return automaton.automatonOutput(state, s.charAt(s.length()-1));
    }
}

class Automaton{
    public String stateTarnslate(String state, char c){
        switch(state){
            case "start":
            {
                if (c == '+' || c == '-') return "sign";
                else if (c >= '0' && c <= '9') return "num";
                else if (c == '.') return "_point";
                else return "end";
            }
            case "sign": {
                if (c >= '0' && c <= '9') return "num";
                else if (c == '.') return "_point";
                else return "end";
            }
            case "num":
            {
                if (c >= '0' && c <= '9') return "num";
                else if (c == '.') return "point";
                else if (c == 'e') return "e";
                else return "end";
            }
            case "_point":
            {
                if (c >= '0' && c <= '9') return "point";
                else return "end";
            }
            case "point":
            {
                if (c >= '0' && c <= '9') return "point";
                else if (c == 'e') return "e";
                else return "end";
            }
            case "e":
            {
                if (c >= '0' && c <= '9') return "e";
                else if (c == '+' || c == '-') return "sign_e";
                else return "end";
            }
            case "sign_e": {
                if (c >= '0' && c <= '9') return "sign_e";
                else return "end";
            }
            default: return "end";
        }
    }

    public boolean automatonOutput(String state, char c){
        switch (state) {
            case "start": return false;
            case "end": return false;
            case "_point": return false;
            case "sign": return false;
            case "point": return true;
            default: {
                if (c >= '0' && c <= '9') return true;
                else return false;
            }
        }
    }
}
//leetcode submit region end(Prohibit modification and deletion)
