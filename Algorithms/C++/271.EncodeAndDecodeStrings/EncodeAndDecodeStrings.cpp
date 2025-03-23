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
        for(auto& str : strs){
            ret += to_string(str.length()) + "#" + str;
        }

        return ret;
    }

    vector<string> decode(string s) {
        vector<string> ret;
        int strIndex = 0;
        while(strIndex < s.length()){
            int keyIndex = strIndex;
            
            while (keyIndex < s.length()){
                if(s[keyIndex] == '#'){
                    break;
                }
                keyIndex++;
            }

            int len = stoi(s.substr(strIndex, keyIndex - strIndex));
            int wordStartIndex = keyIndex + 1;
            ret.push_back(s.substr(wordStartIndex, len));
            strIndex = wordStartIndex + len;
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