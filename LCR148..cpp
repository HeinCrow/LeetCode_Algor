#include<bits/stdc++.h>
using namespace std;
//2025/9/24
//模拟
class Solution {
public:
    bool validateBookSequences(vector<int>& putIn, vector<int>& takeOut) {
        stack<int> stk;
        int i=0,j=0,n=putIn.size(),m=takeOut.size();
        for(j = 0; j < m; j++) {
            while(stk.empty() || stk.top() != takeOut[j]) {
            if(i == n) {
                return false;
            }
            stk.push(putIn[i++]);
            }
            stk.pop();
        }
        return true;
        
    }
};