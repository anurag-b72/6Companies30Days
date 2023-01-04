class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;
    for (string token : tokens) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            // Pop the top two elements from the stack
            int right = stack.top();
            stack.pop();
            int left = stack.top();
            stack.pop();
            // Perform the operation
            if (token == "+") {
                stack.push(left + right);
            } else if (token == "-") {
                stack.push(left - right);
            } else if (token == "*") {
                stack.push(left * right);
            } else if (token == "/") {
                stack.push(left / right);  // Note: this is integer division
            }
        } else {
            // Push the token onto the stack as an integer
            stack.push(atoi(token.c_str()));
        }
    }
    // Return the final result from the stack
    return stack.top();
    }
};