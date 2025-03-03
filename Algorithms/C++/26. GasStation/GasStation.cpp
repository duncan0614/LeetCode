#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0)){
            return -1;
        }

        int total = 0, ret = 0;
        for (int i = 0; i <= gas.size() - 1; i++){
            total += (gas[i] - cost[i]);
            
            if (total < 0){
                total = 0;
                ret = i + 1;
            }
        }

        return ret;
    }
};

int main() {
    Solution solution;

    // Test input
    vector<int> gas = {1,2,3,4};
    vector<int> cost = {2,2,4,1};

    // Call the function
    int result = solution.canCompleteCircuit(gas, cost);

    // Print the output
    cout << "can Complete Circuit:" << to_string(result) << endl;


    return 0;
}