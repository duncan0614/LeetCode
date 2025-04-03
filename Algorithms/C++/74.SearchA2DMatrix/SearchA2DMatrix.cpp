#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ROW = matrix.size(), COL = matrix[0].size();

        int lIndex = 0, rIndex = ROW * COL - 1;
        while (lIndex <= rIndex){
            int mid = ((rIndex - lIndex) / 2) + lIndex;
            int r = mid / COL, c = mid % COL;
            if (matrix[r][c] == target){
                return true;
            }
            else if (matrix[r][c] > target){
                rIndex = mid - 1;
            }
            else{
                lIndex = mid + 1;
            }
        }

        return false;
    }
};
    