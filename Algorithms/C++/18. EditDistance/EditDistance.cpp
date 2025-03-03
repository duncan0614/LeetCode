#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length() + 1, vector<int>(word2.length() + 1, 0));

        for (int j = 0; j <= word2.length(); j++){
            dp[word1.length()][j] = word2.length() - j;
        }

        for (int i = 0; i <= word1.length(); i++){
            dp[i][word2.length()] = word1.length() - i;
        }

        for (int i = word1.length() - 1; i >= 0; i--){
            for (int j = word2.length() - 1; j >= 0; j--){
                if (word1[i] == word2[j]){
                    dp[i][j] = dp[i + 1][j + 1];
                }
                else{
                    dp[i][j] = min(dp[i + 1][j], min(dp[i][j + 1], dp[i + 1][j + 1])) + 1;
                }
            }
        }

        return dp[0][0];
    }
};

int main() {
    Solution solution;

    // Test input
    string word1 = "planning";
    string word2 = "plannt";

    // Call the function
    int result = solution.minDistance(word1, word2);

    // Print the output
    cout << "Min Distance:" << to_string(result) << endl;


    return 0;
}