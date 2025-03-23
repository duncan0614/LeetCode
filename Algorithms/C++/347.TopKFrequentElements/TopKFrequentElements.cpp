#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> numCountMap;
        vector<vector<int>> countNum(nums.size() +1);
        for(int i = 0; i < nums.size(); i++){
            numCountMap[nums[i]] += 1;
        }

        for(auto& num : numCountMap){
            countNum[num.second].push_back(num.first);
        }

        vector<int> ret;
        for(int i = countNum.size() - 1; i > 0; --i){
            for(int n : countNum[i]){

                ret.push_back(n);
                if(ret.size() == k){
                    return ret;
                }
            }
            
        }

        return ret;
    }
};

int main() {
    Solution solution;

    // Test input
    vector<int> nums = {1,2,2,3,3,3};
    int k = 2;

    // Call the function
    vector<int> result = solution.topKFrequent(nums, k);

    // Print the output
    cout << "Grouped Anagrams:" << endl;
    for (const auto& num : result) {
        cout << "[ ";
        cout << num;
        cout << "]" << endl;
    }

    return 0;
}
