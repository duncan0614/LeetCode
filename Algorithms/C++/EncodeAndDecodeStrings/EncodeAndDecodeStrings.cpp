#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:

    string encode(vector<string>& strs) {
        string ret;
        for(const string& str : strs){
            ret += to_string(str.size()) + "#" + str;
        }
        return ret;
    }

    vector<string> decode(string s) {
        vector<string> ret;
        int i = 0;
        while (i < s.size()){
            int j = i;
            while (s[j] != '#'){
                j++;
            }
            
            int len = stoi(s.substr(i, j - i));
            i = j + 1 + len;
            ret.push_back(s.substr(j + 1, len));
            
        }
        return ret;
    }
};

int main() {
    Solution solution;

    // Test input
    vector<string> strs = {"we","say",":","yes","!@#$%^&*()"};

    // Call the function
    string encodeRet = solution.encode(strs);

    vector<string> decodeRet = solution.decode(encodeRet);

    // Print the output
    cout << "Encode and Decode:" << endl;
    for (const auto& str : decodeRet) {
        cout << "[";
        cout << str;
        cout << "]" << endl;
    }

    return 0;
}