#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

int evaluate(vector<string> tokens) {
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

int main() {
    // Example 1: ["2", "1", "+", "3", "*"] => ((2 + 1) * 3) = 9
    vector<string> tokens1 = {"2", "1", "+", "3", "*"};
    cout << evaluate(tokens1) << endl;  // Outputs: 9

    // Example 2: ["4", "13", "5", "/", "+"] => (4 + (13 / 5)) = 6
    vector<string> tokens2 = {"4", "13", "5", "/", "+"};
    cout << evaluate(tokens2) << endl;  // Outputs: 6

    // Example 3: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"] => ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
    vector<string> tokens3 = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    cout << evaluate(tokens3) << endl;  // Outputs: 22

    return 0;
}
