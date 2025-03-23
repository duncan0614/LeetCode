#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }

        unordered_map<char, int> sCharMap;
        unordered_map<char, int> tCharMap;

        for(int i = 0; i <s.size(); i++){
            sCharMap[s[i]] += 1; 
            tCharMap[t[i]] += 1; 
        }

        for(auto item : sCharMap){
            if(sCharMap[item.first] != tCharMap[item.first]){
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution solution;

    // Test input
    string s = "a", t = "ab";

    // Call the function
    bool result = solution.isAnagram(s, t);

    // Print the output
    cout << "Longest Consecutive:" << to_string(result);

    return 0;
}