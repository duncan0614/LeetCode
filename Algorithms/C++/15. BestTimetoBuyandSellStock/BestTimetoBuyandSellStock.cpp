#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0;
        int firstyBuy = prices[0];

        for (auto& price : prices){
            if (price <= firstyBuy){
                firstyBuy = price;
                continue;
            }
            else{
                ret = max(ret, price - firstyBuy);
            }
        }
        return ret;
    }
};

int main() {
    Solution solution;

    // Test input
    vector<int> nums = {7,1,5,3,6,4};

    // Call the function
    int result = solution.maxProfit(nums);

    // Print the output
    cout << "maxProfit:" << to_string(result) << endl;

    return 0;
}