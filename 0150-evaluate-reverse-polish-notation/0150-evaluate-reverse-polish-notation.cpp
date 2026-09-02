class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        
        for (const string& token : tokens) {
            // If the token is an operator, pop the top two elements and calculate
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int rightOperand = st.top(); 
                st.pop();
                
                int leftOperand = st.top(); 
                st.pop();
                
                if (token == "+") st.push(leftOperand + rightOperand);
                else if (token == "-") st.push(leftOperand - rightOperand);
                else if (token == "*") st.push(leftOperand * rightOperand);
                else if (token == "/") st.push(leftOperand / rightOperand);
            } 
            // If the token is a number, convert it to an integer and push to stack
            else {
                st.push(stoi(token));
            }
        }
        
        // The final remaining element is the total result
        return st.top();
    }
};