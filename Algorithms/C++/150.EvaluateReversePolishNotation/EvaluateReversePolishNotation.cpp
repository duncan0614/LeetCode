#include <vector>
#include <unordered_set>
#include <set>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        set<string> operators = {"+", "-", "/", "*"};
        stack<int> nums;

        for (const auto& token : tokens){
            if (operators.count(token)){
                int num1 = nums.top();
                nums.pop();
                int num2 = nums.top();
                nums.pop();
                
                int total = 0;
                if (token == "+"){
                    total = num2 + num1;
                }
                else if (token == "-"){
                    total = num2 - num1;
                }
                else if (token == "/"){
                    total = num2 / num1;
                }
                else{
                    total = num2 * num1;
                }

                nums.push(total);
                continue;
            }

            nums.push(stoi(token));
        }

        return nums.top();
    }
};

int main() {
    Solution solution;

    // Test input
    vector<string> tokens = {"1","2","+","3","*","4","-"};

    // Call the function
    int result = solution.evalRPN(tokens);

    // Print the output
    cout << "Eval RPN:" << to_string(result) << endl;


    return 0;
}