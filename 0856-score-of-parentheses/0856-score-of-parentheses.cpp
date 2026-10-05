class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> shaun_stack;
        shaun_stack.push(0);

        for(int val : s){
            if(val == '('){
                shaun_stack.push(0);
            }
            else{
                int v = shaun_stack.top();
                shaun_stack.pop();
                int score = (v == 0) ? 1 : 2 * v;
                shaun_stack.top() += score;
            }
        }
        return shaun_stack.top();
    }
};