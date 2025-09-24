#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countTarget(vector<int>& scores, int target) {
        int m, n = scores.size(), cnt = 1, l = 0, r = n-1;
        while(l <= r ) {
            m = l + (r - l)/2;
            if(scores[m] == target) {
                r = m-1;
            }
            else if(scores[m] < target) {
                l = m+1;
            }
            else {
                r = m-1;
            }
        }
        if(l == n || scores[l] != target) {
            return 0;
        }
        while(l+1 != n && scores[l+1] == target) {
            cnt++;
            l++;
        }
        return cnt;



        
    }
};