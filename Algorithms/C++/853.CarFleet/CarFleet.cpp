#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pair;
        for (int i = 0; i < position.size(); i++){
            pair.push_back({position[i], speed[i]});
        }

        sort(pair.rbegin(), pair.rend());
        vector<double> stack;
        for (auto& p : pair){
            stack.push_back((double)(target - p.first) / p.second);
            if (stack.size() >= 2 && stack.back() <= stack[stack.size() - 2]){
                stack.pop_back();
            }
        }

        return stack.size();
    }
};

int main() {
    Solution solution;

    int target = 10;
    vector<int> position = {4,1,0,7}, speed = {2,2,1,1};

    // Call the function
    int result = solution.carFleet(target, position, speed);

    // Print the output
    cout << "Car Fleet:" << to_string(result) << endl;
    return 0;
}
    