#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lIndex = 0, rIndex = nums.size() - 1;

        while (lIndex <= rIndex){
            int mid = (rIndex - lIndex) / 2 + lIndex;
            if (nums[mid] == target){
                return mid;
            }

            if (nums[lIndex] <= nums[mid]){
                if (target > nums[mid] || target < nums[lIndex]){
                    lIndex = mid + 1;
                }
                else{
                    rIndex = mid - 1;
                }
            }
            else{
                if (target < nums[mid] || target > nums[rIndex]){
                    rIndex = mid - 1;
                }
                else{
                    lIndex = mid + 1;
                }
            }
        }

        return -1;
    }
};
    