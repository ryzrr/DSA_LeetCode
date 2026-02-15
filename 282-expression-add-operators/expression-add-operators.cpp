class Solution {
public:
    
    void solve(string num, int target, int index,
               long long currentValue,
               long long lastOperand,
               string expression,
               vector<string>& result) {
        
        // Base Case
        if (index == num.length()) {
            if (currentValue == target) {
                result.push_back(expression);
            }
            return;
        }

        for (int i = index; i < num.length(); i++) {

            // 🚫 Leading zero case
            if (i > index && num[index] == '0')
                break;

            string part = num.substr(index, i - index + 1);
            long long number = stoll(part);

            if (index == 0) {
                // First number → no operator
                solve(num, target, i + 1,
                      number,
                      number,
                      part,
                      result);
            }
            else {
                // Addition
                solve(num, target, i + 1,
                      currentValue + number,
                      number,
                      expression + "+" + part,
                      result);

                // Subtraction
                solve(num, target, i + 1,
                      currentValue - number,
                      -number,
                      expression + "-" + part,
                      result);

                // Multiplication (handle precedence)
                solve(num, target, i + 1,
                      currentValue - lastOperand + lastOperand * number,
                      lastOperand * number,
                      expression + "*" + part,
                      result);
            }
        }
    }


    vector<string> addOperators(string num, int target) {
        vector<string> result;
        solve(num, target, 0, 0, 0, "", result);
        return result;
    }
};
