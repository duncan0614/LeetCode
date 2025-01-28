#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
    public:
        bool hasDuplicate(vector<int>& nums) {
            unordered_set<int> numSet;

            for(const int& num : nums){
                if(numSet.find(num) != numSet.end()){
                    return true;
                }

                numSet.insert(num);
            }
            return false;
        }
    };