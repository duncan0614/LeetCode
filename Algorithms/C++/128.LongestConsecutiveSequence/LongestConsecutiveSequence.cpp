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

        unordered_map<int, int> countLongest;
        int longest = 0;

        for(int num : nums){

            if(!countLongest[num]){
                countLongest[num] = countLongest[num - 1] + countLongest[num + 1] + 1;
                countLongest[num - countLongest[num - 1]] = countLongest[num];
                countLongest[num + countLongest[num + 1]] = countLongest[num];
                longest = max(longest, countLongest[num]);
            }
        }

        return longest;
    }
};

int main() {
    Solution solution;

    // Test input
    vector<int> nums = {100, 4, 200, 1, 3, 2};

    // Call the function
    int result = solution.longestConsecutive(nums);

    // Print the output
    cout << "Longest Consecutive:" << to_string(result);

    return 0;
}