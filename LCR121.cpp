#include<bits/stdc++.h>
using namespace std;
//关注右上角，逐步缩小范围
class Solution {
public:
    bool findTargetIn2DPlants(vector<vector<int>>& plants, int target) {
        if(plants.size() == 0 || plants[0].size() == 0) {
            return false;
        }
        int m = plants.size(), n = plants[0].size(), i = 0, j = n-1;
        while(i < m && j >= 0) {
            if(plants[i][j] == target) {
                return true;
            }
            else if(plants[i][j] > target) {
                j--;
            }
            else {
                i++;
            }
        } 
        return false;
        
    }
};