#include <vector>
#include <set>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize){
            return false;
        }
        unordered_map<int, int> numMap;
        for (const auto& num : hand){
            numMap[num] += 1;
        }

        priority_queue<int, vector<int>, greater<>> minHeap;
        for (auto& pair : numMap){
            minHeap.push(pair.first);
        }

        while (!minHeap.empty()){
            int first = minHeap.top();
            for (int i = first; i < first + groupSize; i++){
                if (numMap.find(i) == numMap.end()){
                    return false;
                }

                numMap[i] -= 1;
                if (numMap[i] == 0){
                    if (i != minHeap.top()){
                        return false;
                    }
                    minHeap.pop();
                }
            }
        }
        return true;
    }
};

int main() {
    Solution solution;

    // Test input
    vector<int> numlist = {1,2,3,3,4,5,6,7};
    int groupSize = 4;

    // Call the function
    bool result = solution.isNStraightHand(numlist, groupSize);

    // Print the output
    cout << "is NStraight Hand:" << to_string(result) << endl;


    return 0;
}