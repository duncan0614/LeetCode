#include <unordered_map>
#include <vector>
#include <string>
#include <stdio.h>
using namespace std;

class TimeMap {
    private:
        unordered_map<string, vector<pair<int, string>>> timeMap;
    
    public:
        TimeMap() {}
        
        void set(string key, string value, int timestamp) {
            timeMap[key].emplace_back(timestamp, value);
        }
        
        string get(string key, int timestamp) {
            auto& values = timeMap[key];
            int lIndex = 0, rIndex = values.size() - 1;
            string ret = "";
    
            while (lIndex <= rIndex){
                int mid = (rIndex - lIndex) / 2 + lIndex;
                if (values[mid].first <= timestamp) {
                    ret = values[mid].second;
                    lIndex = mid + 1;
                }
                else {
                    rIndex = mid - 1;
                }
            }
    
            return ret;
        }
    };
    