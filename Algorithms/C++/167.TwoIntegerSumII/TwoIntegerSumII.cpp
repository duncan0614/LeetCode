#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        vector<int> ret;
        while (i < j){
            if(numbers[i] + numbers[j] > target){
                j--;
                continue;
            }
            else if(numbers[i] + numbers[j] < target){
                i++;
                continue;
            }

            ret.push_back(i+1);
            ret.push_back(j+1);
            break;
        }
        
        return ret;
    }
};

int main() {
    Solution solution;

    // Test input
    vector<int> nums = {1,2,3,4};
    int t = 3;

    // Call the function
    vector<int> result = solution.twoSum(nums, t);

    // Print the output
    cout << "two Sum:" << endl;
    for (const auto& num : result) {
        cout << "[";
        cout << to_string(num);
        cout << "]" << endl;
    }

    return 0;
}
