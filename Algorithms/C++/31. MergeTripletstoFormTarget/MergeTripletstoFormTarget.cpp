#include <vector>
#include <unordered_set>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        unordered_set<int> ret;

        for (const auto& triple : triplets){
            if (triple[0] > target[0] || triple[1] > target[1] || triple[2] > target[2]){
                continue;
            }

            for (int i = 0; i < triple.size(); i++){
                if (triple[i] == target[i]){
                    ret.insert(i);
                }
            }
        }

        return ret.size() == 3;
    }
};

int main() {
    Solution solution;

    // Test input
    vector<vector<int>> triplets = {{2,5,3},{2,3,4},{1,2,5},{5,2,3}};
    vector<int> target = {5,5,5};

    // Call the function
    bool result = solution.mergeTriplets(triplets, target);

    // Print the output
    cout << "merge Triplets:" << to_string(result) << endl;


    return 0;
}