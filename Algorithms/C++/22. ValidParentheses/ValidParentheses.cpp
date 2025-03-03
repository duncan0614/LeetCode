#include <vector>
#include <unordered_map>
#include <stack>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isValid(string s) {

        if (s.length() % 2 == 1){
            return false;
        }

        unordered_map<char, char> cMap;
        cMap['('] = ')';
        cMap['{'] = '}';
        cMap['['] = ']';
        stack<char> cstack;

        for (auto& c : s){
            if (cMap.find(c) != cMap.end()){
                cstack.push(c);
            }
            else{
                if (cstack.empty()){
                    return false;
                }
                char tempchar = cstack.top();
                cstack.pop();
                if (cMap[tempchar] != c){
                    return false;
                }
            }
        }

        if (!cstack.empty()){
            return false;
        }
        return true;
    }
};

int main() {
    Solution solution;

    // Test input
    string word1 = "[(])";

    // Call the function
    bool result = solution.isValid(word1);

    // Print the output
    cout << "is Valid:" << to_string(result) << endl;


    return 0;
}