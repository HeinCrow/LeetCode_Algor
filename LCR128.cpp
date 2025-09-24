#include<bits/stdc++.h>
using namespace std;
//2025/9/24
class Solution {
public:
    int bs_min(vector<int>& v, int l, int r) {
        int m, l0 = l, r0 = r;
        if(v[r] > v[l]) {
            return v[l];
        }
        while(l < r) {
            m = l + (r-l)/2;
            if(v[m] < v[l0]) {
                r = m;
            }
            else if(v[m] > v[l0] || v[m] == v[l0] && v[l0] > v[r0]) {
                l = m+1;
            }
            else {
                return min(bs_min(v, l, m), bs_min(v, m+1, r));
            }
        }
        return v[l];
    }
    int inventoryManagement(vector<int>& stock) {
        return bs_min(stock, 0, stock.size()-1);
        
    }
};