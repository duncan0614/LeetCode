#include <vector>
#include <unordered_map>
#include <stack>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    void backtrack(int openN, int closedN, int n, vector<string>& res, string& stack){
        if (openN == closedN && openN == n){
            res.push_back(stack);
            return;
        }

        if (openN < n){
            stack += "(";
            backtrack(openN + 1, closedN, n, res, stack);
            stack.pop_back();
        }

        if (closedN < openN){
            stack += ")";
            backtrack(openN, closedN + 1, n, res, stack);
            stack.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string stack;
        backtrack(0, 0, n, res, stack);
        return res;
    }
};

int main() {
    Solution solution;

    // Call the function
    vector<string> result = solution.generateParenthesis(3);

    // Print the output
    cout << "Generate Parenthesis:" << endl;
    cout << "[";
    for (const auto& item : result) {
        for (const auto& c : item) {
            cout << c << ',';
        }
    }
    cout << "]" << endl;
    return 0;
}