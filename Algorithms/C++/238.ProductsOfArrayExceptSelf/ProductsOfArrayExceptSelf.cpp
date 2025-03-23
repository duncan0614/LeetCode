#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int numsCount = nums.size();
        vector<int> ret(nums.size(), 1);

        for(int i = 1; i < nums.size(); i++){
            ret[i] = ret[i-1] * nums[i-1];
        }

        int prefix = 1;
        for(int i = nums.size() - 1; i >= 0; i--){
            ret[i] *= prefix;
            prefix *= nums[i];
        }

        return ret;
    }
};


int main() {
    Solution solution;

    // Test input
    vector<int> nums = {1,2,4,6};

    // Call the function
    vector<int> result = solution.productExceptSelf(nums);

    // Print the output
    cout << "product Except Self:" << endl;
    for (const auto& str : result) {
        cout << "[";
        cout << str;
        cout << "]" << endl;
    }

    return 0;
}