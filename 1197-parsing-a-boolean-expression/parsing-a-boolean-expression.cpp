class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        
        for (char c : expression) {
            if (c == ',') continue;   // comma ko ignore karo
            
            if (c != ')') {
                st.push(c);   // t, f, &, |, !, ( -- sab push karo
            } else {
                // ')' mila -- ab andar wale group ko process karo
                vector<bool> values;
                
                while (st.top() != '(') {
                    char top = st.top();
                    st.pop();
                    if (top == 't') values.push_back(true);
                    else if (top == 'f') values.push_back(false);
                }
                st.pop();  // '(' ko bhi nikaal do
                
                char op = st.top();  // operator dekho (&, |, ya !)
                st.pop();
                
                bool result;
                if (op == '&') {
                    result = true;
                    for (bool v : values) result = result && v;
                } else if (op == '|') {
                    result = false;
                    for (bool v : values) result = result || v;
                } else { // op == '!'
                    result = !values[0];
                }
                
                // result ko wapas stack mein push karo (t ya f banake)
                st.push(result ? 't' : 'f');
            }
        }
        
        return st.top() == 't';
    }
};