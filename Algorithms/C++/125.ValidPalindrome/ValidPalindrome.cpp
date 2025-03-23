#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.length() - 1;

        while (i < j)
        {   
            if(!isChar(s[i])){
                i++;
                continue;
            }

            if(!isChar(s[j])){
                j--;
                continue;
            }
            cout << s[i] << ',' << s[j];
            if(tolower(s[i]) != tolower(s[j])){
                return false;
            }
            i++;
            j--;
        }
        
        return true;
    }

    bool isChar(char c) {
        if('A' <= c && 'Z' >= c){
            return true;
        }
        else if ('a' <= c && 'z' >= c)
        {
            return true;
        }
        else if ('0' <= c && '9' >= c)
        {
            return true;
        }

        return false;
    }
};

int main() {
    Solution solution;

    // Test input
    string s = "aa";

    // Call the function
    bool result = solution.isPalindrome(s);

    // Print the output
    cout << "IsPalindrome:" << to_string(result);

    return 0;
}
