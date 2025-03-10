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
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> prices(n, INT_MAX);
        prices[src] = 0;

        for (int i = 0; i <= k; i++){
            vector<int> tmpPrices = prices;

            for (const auto& flight : flights){
                int s = flight[0];
                int d = flight[1];
                int p = flight[2];

                if (prices[s] == INT_MAX){
                    continue;
                }

                if (prices[s] + p < tmpPrices[d]){
                    tmpPrices[d] = prices[s] + p;
                }
            }
            prices = tmpPrices;
        }

        return prices[dst] == INT_MAX ? -1 : prices[dst];
    }
};


int main() {
    Solution solution;

    // Test input
    vector<vector<int>> flights = {{0,1,200},{1,2,100},{1,3,300},{2,3,100}};
    int n = 4, src = 0, dst = 3, k = 1; 

    // Call the function
    int result = solution.findCheapestPrice(n, flights, src, dst, k);

    // Print the output
    cout << "find Cheapest Price:" << to_string(result) << endl;

    return 0;
}