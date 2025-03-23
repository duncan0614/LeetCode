#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goal = nums.size() - 1;

        for (int i = nums.size() - 2; i >= 0; i--){
            if (i + nums[i] >= goal){
                goal = i;
            }
        }

        return goal == 0;
    }
};

int main() {
    Solution solution;

    // Test input
    vector<int> numlist = {1,2,0,1,0};

    // Call the function
    bool result = solution.canJump(numlist);

    // Print the output
    cout << "can Jump:" << to_string(result) << endl;


    return 0;
}