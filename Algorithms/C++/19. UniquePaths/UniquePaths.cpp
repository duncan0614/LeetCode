#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <string>
#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        dp[m - 1][n - 1] = 1;

        for (int r = m -1; r >= 0; r--){
            for(int c = n -1; c >= 0; c--){
                dp[r][c] += dp[r + 1][c] + dp[r][c + 1];
            }
        }
        

        return dp[0][0];
    }
};

int main() {
    Solution solution;

    // Test input
    int m = 3;
    int n = 3;

    // Call the function
    int result = solution.uniquePaths(m, n);

    // Print the output
    cout << "Unique Paths:" << to_string(result) << endl;


    return 0;
}