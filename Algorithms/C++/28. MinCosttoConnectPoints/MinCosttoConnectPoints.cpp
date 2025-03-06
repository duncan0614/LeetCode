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
    int minCostConnectPoints(vector<vector<int>>& points) {
        int nodes = points.size();
        unordered_map<int, vector<pair<int, int>>> adj;
        for (int i = 0; i < nodes; i++){
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j = i + 1; j < nodes; j++){
                int x2 = points[j][0];
                int y2 = points[j][1];
                int dist = abs(x2 - x1) + abs(y2 - y1);
                
                adj[i].push_back({dist, j});
                adj[j].push_back({dist, i});
            }
        }

        int res = 0;
        set<int> visited;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        minHeap.push({0, 0});

        while (visited.size() < nodes){
            auto curr = minHeap.top();
            minHeap.pop();

            int cost = curr.first;
            int i = curr.second;
            if (visited.count(i)){
                continue;
            }

            visited.insert(i);
            res += cost;

            for (const auto& point : adj[i]){
                int neiCost = point.first;
                int neiIndex = point.second;
                if (!visited.count(neiIndex)){
                    minHeap.push({neiCost, neiIndex});
                }
            }
        }

        return res;
    }
};

int main() {
    Solution solution;

    // Test input
    vector<vector<int>> points = {{7,7},{8,0},{9,-9},{-3,4}};

    // Call the function
    int result = solution.minCostConnectPoints(points);

    // Print the output
    cout << "Min Cost Connect Points:" << to_string(result) << endl;

    return 0;
}