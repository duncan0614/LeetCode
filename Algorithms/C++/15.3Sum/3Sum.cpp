#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;

        if(nums.size() < 3){
            return ret;
        }

        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++){
            if (nums[i] > 0){
                    break;
            }

            if (i > 0 && nums[i] == nums[i - 1]){
                continue;
            }

            int lIndex = i + 1, rIndex = nums.size() - 1;

            while (lIndex < rIndex){    
                
                if(nums[i] + nums[lIndex] + nums[rIndex] > 0){
                    rIndex--;
                    continue;
                }
                else if (nums[i] + nums[lIndex] + nums[rIndex] < 0){
                    lIndex++;
                    continue;
                }
                else{
                    ret.push_back({nums[i], nums[lIndex], nums[rIndex]});
                    lIndex++;
                    while (nums[lIndex] == nums[lIndex - 1] && lIndex < rIndex){
                        lIndex++;
                    }
                }         
            }
        }
        return ret;
    }
};

int main() {
    Solution solution;

    // Test input
    vector<int> nums = {-1,0,1,2,-1,-4};
    int t = 3;

    // Call the function
    vector<vector<int>> result = solution.threeSum(nums);

    // Print the output
    cout << "Three Sum:" << endl;
    for (const auto& item : result) {
        cout << "[";
        for (const auto& num : item) {
            cout << to_string(num) << ',';
        }
        cout << "]" << endl;
    }

    return 0;
}