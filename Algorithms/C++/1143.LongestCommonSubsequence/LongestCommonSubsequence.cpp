#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

class Solution {
    public:
        int longestCommonSubsequence(string text1, string text2) {
            vector<vector<int>> dp(text1.length() + 1, vector<int>(text2.length() + 1, 0));

            for (int i = text1.length() - 1; i >= 0; i--){
                for (int j = text2.length() - 1; j >= 0; j--){
                    if (text1[i] == text2[j]){
                        dp[i][j] = 1 + dp[i + 1][j + 1];
                    }
                    else{
                        dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                    }
                }
            }
            return dp[0][0];
        }
    };

int main() {
    Solution solution;

    // Test input
    string word1 = "bsbininm";
    string word2 = "jmjkbkjkv";

    // Call the function
    int result = solution.longestCommonSubsequence(word1, word2);

    // Print the output
    cout << "Longest Common Subsequence:" << to_string(result) << endl;


    return 0;
}