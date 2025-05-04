#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast)
                break;
        }

        int slowMatch = 0;
        while (true) {
            slowMatch = nums[slowMatch];
            slow = nums[slow];
            if (slowMatch == slow)
                return slow;
        }
    }
};
    