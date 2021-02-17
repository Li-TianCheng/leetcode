//给定一个化学式formula（作为字符串），返回每种原子的数量。 
//
// 原子总是以一个大写字母开始，接着跟随0个或任意个小写字母，表示原子的名字。 
//
// 如果数量大于 1，原子后会跟着数字表示原子的数量。如果数量等于 1 则不会跟数字。例如，H2O 和 H2O2 是可行的，但 H1O2 这个表达是不可行的。
// 
//
// 两个化学式连在一起是新的化学式。例如 H2O2He3Mg4 也是化学式。 
//
// 一个括号中的化学式和数字（可选择性添加）也是化学式。例如 (H2O2) 和 (H2O2)3 是化学式。 
//
// 给定一个化学式，输出所有原子的数量。格式为：第一个（按字典序）原子的名子，跟着它的数量（如果数量大于 1），然后是第二个原子的名字（按字典序），跟着它的数
//量（如果数量大于 1），以此类推。 
//
// 示例 1: 
//
// 
//输入: 
//formula = "H2O"
//输出: "H2O"
//解释: 
//原子的数量是 {'H': 2, 'O': 1}。
// 
//
// 示例 2: 
//
// 
//输入: 
//formula = "Mg(OH)2"
//输出: "H2MgO2"
//解释: 
//原子的数量是 {'H': 2, 'Mg': 1, 'O': 2}。
// 
//
// 示例 3: 
//
// 
//输入: 
//formula = "K4(ON(SO3)2)2"
//输出: "K4N2O14S4"
//解释: 
//原子的数量是 {'K': 4, 'N': 2, 'O': 14, 'S': 4}。
// 
//
// 注意: 
//
// 
// 所有原子的第一个字母为大写，剩余字母都是小写。 
// formula的长度在[1, 1000]之间。 
// formula只包含字母、数字和圆括号，并且题目中给定的是合法的化学式。 
// 
// Related Topics 栈 递归 哈希表 
// 👍 110 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public String countOfAtoms(String formula) {
        String result = "";
        TreeMap<String, Integer> map = new TreeMap<>();
        help(formula, map, 1);

        for (Map.Entry<String, Integer> entry : map.entrySet()) {
            result += entry.getKey();
            if (entry.getValue() != 1){
                result += entry.getValue().toString();
            }
        }
        return result;
    }

    private void help(String formula, TreeMap<String,Integer> map, int rate) {
        String key = "";
        Stack<Character> stack = new Stack<>();
        int num = 0;
        int index = 0;
        while (index < formula.length()) {
            if (formula.charAt(index) >= 'A' && formula.charAt(index)  <= 'Z') {
                if (!key.isEmpty()){
                    if (!map.containsKey(key)){
                        map.put(key, 0);
                    }
                    map.put(key, map.get(key)+(num == 0 ? 1 : num) * rate);
                }
                key = "";
                key += formula.charAt(index);
                num = 0;
                index++;
                continue;
            }
            if (formula.charAt(index)  >= 'a' && formula.charAt(index)  <= 'z') {
                key += formula.charAt(index) ;
                index++;
                continue;
            }
            if (formula.charAt(index)  >= '0' && formula.charAt(index)  <= '9'){
                num = num * 10 + formula.charAt(index)  - '0';
                index++;
                continue;
            }
            if (formula.charAt(index)  == '('){
                int temp = index;
                int tempRate = 0;
                stack.push(formula.charAt(index) );
                while (!stack.empty()){
                    temp++;
                    if (formula.charAt(temp)  == ')'){
                        stack.pop();
                    }
                    if (formula.charAt(temp) == '('){
                        stack.push(formula.charAt(temp));
                    }
                }
                String sub = formula.substring(index+1, temp);
                temp++;
                while (temp < formula.length() && formula.charAt(temp) <= '9' && formula.charAt(temp) >= '0'){
                    tempRate = tempRate * 10 + formula.charAt(temp) - '0';
                    temp++;
                }
                tempRate = tempRate == 0 ? 1 : tempRate;
                help(sub, map, rate*tempRate);
                index = temp;
            }
        }
        if (!key.isEmpty()){
            if (!map.containsKey(key)){
                map.put(key, 0);
            }
            map.put(key, map.get(key)+(num == 0 ? 1 : num) * rate);
        }
    }
}
//leetcode submit region end(Prohibit modification and deletion)
