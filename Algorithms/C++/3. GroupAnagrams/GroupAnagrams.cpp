#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> tempMap;
        for (const auto& s : strs){
            vector<int> count(26);
            for (char c : s){
                count[c - 'a'] += 1;
            }

            string key = to_string(count[0]);
            for(int i = 0; i < 26; ++i){
                key += ',' + to_string(count[i]);
            }

            tempMap[key].push_back(s);
        }

        vector<vector<string>> ret;
        for(const auto& pair : tempMap){
            ret.push_back(pair.second);
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
