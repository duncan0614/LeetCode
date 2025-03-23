#include <vector>
#include <unordered_set>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> charMap;
        for (int i = 0; i < s.length(); i++){
            charMap[s[i]] = i;
        }

        vector<int> subCount;
        int size = 0, end = 0;
        for (int i = 0; i < s.length(); i++){
            size++;
            end = max(end, charMap[s[i]]);

            if (end == i){
                subCount.push_back(size);
                size = 0;
            }
        }
        
        return subCount;
    }
};

int main() {
    Solution solution;

    // Test input
    string s = "xyxxyzbzbbisl";

    // Call the function
    vector<int> result = solution.partitionLabels(s);

    // Print the output
    cout << "partition Labels:" << endl;
    cout << "[";
    for (const auto& num : result) {
        cout << num;
        cout << ",";
    }
    cout << "]" << endl;


    return 0;
}