#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;

        for(int i = 0; i < nums.size(); i++){
            numMap[nums[i]] = i;
        }

        for(int i = 0; i < nums.size(); i++){
            int ans = target - nums[i];
            if(numMap.count(ans) && numMap[ans] != i){
                return {i, numMap[ans]};
            }
        }
        return {};
    }
};