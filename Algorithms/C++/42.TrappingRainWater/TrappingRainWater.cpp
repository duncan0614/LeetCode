#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int ret = 0;

        if (height.size() == 0){
            return ret;
        }

        int lIndex = 0, rIndex = height.size() - 1;
        int theMostLeft = height[lIndex], theMostRight = height[rIndex];

        while (lIndex < rIndex){
            if (theMostLeft < theMostRight){
                lIndex++;
                theMostLeft = max(theMostLeft, height[lIndex]);
                ret += theMostLeft - height[lIndex];
            }
            else{
                rIndex--;
                theMostRight = max(theMostRight, height[rIndex]);
                ret += theMostRight - height[rIndex];
            }
        }
        
        return ret;
    }
};

int main() {
    Solution solution;

    // Test input
    vector<int> nums = {0,2,0,3,1,0,1,3,2,1};

    // Call the function
    int result = solution.trap(nums);

    // Print the output
    cout << "trap:" << to_string(result) << endl;

    return 0;
}