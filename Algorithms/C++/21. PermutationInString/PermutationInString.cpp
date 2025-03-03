#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

class Solution {
    public:
        bool checkInclusion(string s1, string s2) {            
            if (s1.length() > s2.length()){
                return false;
            }

            vector<int> s1Count(26, 0);
            vector<int> s2Count(26, 0);
            for (int i = 0; i < s1.length(); i++){
                s1Count[s1[i] - 'a']++;
                s2Count[s2[i] - 'a']++;
            }

            int matches = 0;
            for (int i = 0; i < 26; i++){
                if (s1Count[i] == s2Count[i]){
                    matches++;
                }
            }

            int l = 0;
            for (int r = s1.length(); r < s2.length(); r++) {
                if (matches == 26){
                    return true;
                }

                int index = s2[r] - 'a';
                s2Count[index]++;
                if (s1Count[index] == s2Count[index]) {
                    matches++;
                }
                else if (s1Count[index] + 1 == s2Count[index]){
                    matches--;
                }

                index = s2[l] - 'a';
                s2Count[index]--;
                if (s1Count[index] == s2Count[index]) {
                    matches++;
                }
                else if (s1Count[index] - 1 == s2Count[index]){
                    matches--;
                }
                l++;
            }

            return matches == 26;
        }
    };

int main() {
    Solution solution;

    // Test input
    string word1 = "abc";
    string word2 = "lecabee";

    // Call the function
    bool result = solution.checkInclusion(word1, word2);

    // Print the output
    cout << "Check in clusion:" << to_string(result) << endl;


    return 0;
}