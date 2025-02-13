#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxArea = 0;
        int lIndex = 0, rIndex = heights.size() - 1;

        while (lIndex < rIndex){
            
            int tempArea = 0;
            if (heights[lIndex] >= heights[rIndex]){
                tempArea = heights[rIndex] * (rIndex - lIndex);
                rIndex--;
            }
            else{
                tempArea = heights[lIndex] * (rIndex - lIndex);
                lIndex++;
            }

            if (tempArea > maxArea){
                maxArea = tempArea;
            }

        }
        
        return maxArea;
    }
};


int main() {
    Solution solution;

    // Test input
    vector<int> nums = {1,7,2,5,4,7,3,6};

    // Call the function
    int result = solution.maxArea(nums);

    // Print the output
    cout << "max Area:" << to_string(result) << endl;

    return 0;
}