#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ret(temperatures.size(), 0);
        stack<pair<int, int>> stack;
        
        for (int i = 0; i < temperatures.size(); i++){
            int t = temperatures[i];
            while (!stack.empty() && t > stack.top().first){
                auto pair = stack.top();
                stack.pop();
                ret[pair.second] = i - pair.second;
            }

            stack.push({t, i});
        }

        return ret;
    }
};