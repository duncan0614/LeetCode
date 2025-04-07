#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int findMin(vector<int> &nums) {
        int lIndex = 0, rIndex = nums.size() - 1, ret = nums[0];
        while (lIndex <= rIndex){
            if (nums[lIndex] < nums[rIndex]){
                ret = min(ret, nums[lIndex]);
                break;
            }

            int mid = (rIndex - lIndex) / 2 + lIndex;
            ret = min(ret, nums[mid]);

            if (nums[mid] >= nums[lIndex]){
                lIndex = mid + 1;
            }
            else{
                rIndex = mid - 1;
            }

        }

        return ret;
    }
};
    
    int main() {
        Solution solution;
        
        // Test input
        vector<int> nums = {3,4,5,6,1,2};

        // Call the function
        int result = solution.findMin(nums);
    
        // Print the output
        cout << "Find Min:" << to_string(result) << endl;
        return 0;
    }