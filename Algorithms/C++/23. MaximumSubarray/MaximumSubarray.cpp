#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSub = nums[0];
        int currentSub = 0;
        for (int& num : nums){
            if (currentSub < 0){
                currentSub = 0;
            }

            currentSub += num;
            maxSub = max(maxSub, currentSub);
        }

        return maxSub;
    }
};

int main() {
    Solution solution;

    // Test input
    vector<int> nums = {-6,-2,-1,-4};

    // Call the function
    int result = solution.maxSubArray(nums);

    // Print the output
    cout << "max SubArray:" << to_string(result) << endl;


    return 0;
}