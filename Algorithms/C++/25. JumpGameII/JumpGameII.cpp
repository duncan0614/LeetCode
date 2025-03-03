#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int ret = 0;
        int lIndex = 0, rIndex = 0;

        while (rIndex < nums.size() - 1){
            int farthest = 0;
            for (int i = lIndex; i < rIndex + 1; i++){
                farthest = max(farthest, i + nums[i]);
            }
            lIndex = rIndex + 1;
            rIndex = farthest;
            ret++;
        }

        return ret;
    }
};

int main() {
    Solution solution;

    // Test input
    vector<int> numlist = {2,4,1,1,1,1};

    // Call the function
    int result = solution.jump(numlist);

    // Print the output
    cout << "Jump:" << to_string(result) << endl;


    return 0;
}