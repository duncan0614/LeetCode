#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_map<int, int> countNums;
        int longest  = 0;

        for (int num : nums){

            if (!countNums[num]){
                countNums[num] = countNums[num - 1] + countNums[num + 1] + 1;
                countNums[num - countNums[num - 1]] = countNums[num];
                countNums[num + countNums[num + 1]] = countNums[num];
                longest = max(longest, countNums[num]);
            }
        }

        return longest;
    }
};

int main() {
    Solution solution;

    // Test input
    vector<int> nums = {2,20,4,10,3,4,5};

    // Call the function
    int result = solution.longestConsecutive(nums);

    // Print the output
    cout << "Longest Consecutive:" << to_string(result);

    return 0;
}