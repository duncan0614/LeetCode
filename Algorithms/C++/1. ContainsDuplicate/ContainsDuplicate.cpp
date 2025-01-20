#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
    public:
        bool hasDuplicate(vector<int>& nums) {
            unordered_set<int> checkSuccess;

            for (int num : nums){
                if (checkSuccess.count(num)) {
                    return true;
                }
                checkSuccess.insert(num);
            }

            return false;
        }
    };