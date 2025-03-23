#include <vector>
#include <unordered_set>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

class MinStack {
private:
    long min;
    std::stack<long> s;
public:
    MinStack() {
    }
    
    void push(int val) {
        if (s.empty()){
            s.push(0);
            min = val;
        }
        else{
            s.push(val - min);
            if (val < min){
                min = val;
            }
        }
    }
    
    void pop() {
        long num = s.top();
        s.pop();
        if (num < 0){
            min = min - num;
        }
    }
    
    int top() {
        long num = s.top();
        return (num > 0) ? (num + min) : int(min);
    }
    
    int getMin() {
        return int(min);
    }
};
    