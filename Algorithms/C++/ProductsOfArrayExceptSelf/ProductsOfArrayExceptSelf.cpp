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
        int count = nums.size();
        vector<int> ret(count, 1);

        for (int i = 1; i < count; i++) {
            ret[i] = ret[i - 1] * nums[i - 1];
        }
        
        int postfix = 1;
        for (int i = count - 1; i >= 0; i--) {
            ret[i] *= postfix;
            postfix *= nums[i];
        }
        return ret;
    }
};


int main() {
    Solution solution;

    // Test input
    vector<int> nums = {0,2,3,4};

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