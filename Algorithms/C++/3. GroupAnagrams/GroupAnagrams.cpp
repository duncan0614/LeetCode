#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> stringGroup;
        for(auto str: strs){
            vector<int> charNum(26);

            // every char in string
            for(char c : str){
                charNum[c - 'a'] += 1;
            }

            string key = to_string(charNum[0]);
            for(int i = 0; i < 26; ++i){
                key += ',' + to_string(charNum[i]);
            }

            stringGroup[key].push_back(str);  

        }

        vector<vector<string>> ret;
        for(auto item : stringGroup){
            ret.push_back(item.second);
        }
        return ret; 
    }
};

int main() {
    Solution solution;

    // Test input
    vector<string> strs = {""};

    // Call the function
    vector<vector<string>> result = solution.groupAnagrams(strs);

    // Print the output
    cout << "Grouped Anagrams:" << endl;
    for (const auto& group : result) {
        cout << "[ ";
        for (const string& word : group) {
            cout << word << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
