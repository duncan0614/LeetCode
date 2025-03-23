#include <vector>
#include <algorithm>
#include <unordered_set>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charList;
        int lIndex = 0;
        int ret = 0;
        for (int rIndex = 0; rIndex < s.length(); rIndex++){

            while (charList.find(s[rIndex]) != charList.end()){
                charList.erase(s[lIndex]);
                lIndex++;
            }

            charList.insert(s[rIndex]);
            ret = max(ret, rIndex - lIndex + 1);
        }

        return ret;
    }
};

int main() {
    Solution solution;

    // Test input
    string str = "zxyzxyz";

    // Call the function
    int result = solution.lengthOfLongestSubstring(str);

    // Print the output
    cout << "lengthOfLongestSubstring:" << to_string(result) << endl;

    return 0;
}