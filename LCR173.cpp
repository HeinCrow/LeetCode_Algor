#include<bits/stdc++.h>
using namespace std;
//二分查找
class Solution {
public:
    int takeAttendance(vector<int>& records) {
        int n = records.size(), l = 0, r = n-1, m;
        while(l <= r) {
            m = l + (r - l)/2;
            if(records[m] == m) {
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
    
        return l;
    }
};