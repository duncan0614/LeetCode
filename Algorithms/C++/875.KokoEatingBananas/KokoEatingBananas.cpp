#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

class Solution {
    public:
        int minEatingSpeed(vector<int>& piles, int h) {
            int lIndex = 1;
            int rIndex = *max_element(piles.begin(), piles.end());
            int ret = rIndex;
    
            while (lIndex <= rIndex){
                int mid = (rIndex + lIndex) / 2;
                long count = 0;
                for (const int& p : piles){
                    if (p % mid != 0){
                        count += p / mid + 1;
                    }
                    else{
                        count += p / mid;
                    }
                }
    
                if (count <= h){
                    ret = mid;
                    rIndex = mid - 1;
                }
                else{
                    lIndex = mid + 1;
                }
            }
            
            return ret;
        }
    };
    