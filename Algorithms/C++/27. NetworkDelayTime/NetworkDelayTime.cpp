#include <vector>
#include <set>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <numeric>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> edges;
        for (const auto& time : times){
            edges[time[0]].emplace_back(time[1], time[2]);
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        minHeap.push({0, k});

        set<int> visited;
        int t = 0;

        while (!minHeap.empty()){
            auto curr = minHeap.top();
            minHeap.pop();

            int w1 = curr.first, n1 = curr.second;
            if (visited.count(n1)){
                continue;
            }

            visited.insert(n1);
            t = w1;

            if (edges.count(n1)){
                for (const auto& next : edges[n1]){
                    int w2 = next.second, n2 = next.first;
                    if (!visited.count(n2)){
                        minHeap.push({w1 + w2, n2});
                    }
                }
            }
        }
        
        return visited.size() == n ? t : -1;
    }
};

int main() {
    Solution solution;

    // Test input
    vector<vector<int>> times = {{1,2,1},{2,3,1},{1,4,4},{3,4,1}};
    int n = 4, k = 1;

    // Call the function
    int result = solution.networkDelayTime(times, n, k);

    // Print the output
    cout << "network Delay Time:" << to_string(result) << endl;


    return 0;
}