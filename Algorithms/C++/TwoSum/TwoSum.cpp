#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> numbers;

        for(int i = 0; i < nums.size(); i++){
            numbers[nums[i]] = i;
        }

        for(int i = 0; i < nums.size(); i++){
            int tempnum = target - nums[i];
            // find the tempnum in the numbers and check it is not the same index
            if(numbers.count(tempnum) && numbers[tempnum] != i){
                return {i, numbers[tempnum]};
            }
        }

        return {};
    }
};