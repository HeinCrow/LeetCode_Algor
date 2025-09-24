#include<bits/stdc++.h>
using namespace std;
//2025/9/23
//法一（Hein）：模拟（观察每次在一个方向上遍历所经路径所经点塑变化规律）
class Solution {
public:
    vector<int> spiralArray(vector<vector<int>>& array) {
        if(array.size() == 0 || array[0].size() == 0) {
            return {};
        }
        vector<int> ans;
        int m = array.size(), n = array[0].size(), i, j, imax = m, jmax = n+1, x = 0, y = -1;
        int dir = 3;
        while(1) {
            dir = dir == 3 ? 0 : dir+1;
            if(dir%2 == 0) {
                if(jmax == 1) {
                    return ans;
                }
                for(j = 2; j <= jmax; j++) {
                    if(dir == 0) {
                        y++;
                    }
                    else {
                        y--;
                    }
                    ans.push_back(array[x][y]);
                }
                jmax--;
            }
            if(dir%2 == 1) {
                if(imax == 1) {
                    return ans;
                }
                for(i = 2; i <= imax; i++) {
                    if(dir == 1) {
                        x++;
                    }
                    else {
                        x--;
                    }
                    ans.push_back(array[x][y]);
                }
                imax--;
            }
        }
        return ans;
        
    }
};

//法二：模拟（由外向内逐层遍历, 每层由它的左上角 (top, left) 和右上角 (bottom, right)确定,
//每层遍历顺序 1. left -> right 2. top+1 -> bottom 3. right-1 -> left+1 4. left -> top+1
//（又是关注和借助左上角哈哈哈）
class Solution2 {
public:
    vector<int> spiralArray(vector<vector<int>>& array) {
        if(array.size() == 0 || array[0].size() == 0) {
            return {};
        }
        vector<int> ans;
        int top = 0, left = 0, right = array[0].size()-1, bottom = array.size()-1, x, y;
        while(top <= bottom && left <= right) {
            for(y = left; y <= right; y++) {
                ans.push_back(array[top][y]);
            }
            for(x = top+1; x <= bottom; x++) {
                ans.push_back(array[x][right]);
            }
            for(y = right-1; y >= left+1; y--) {
                ans.push_back(array[bottom][y]);
            }
            for(x = bottom; x >= top+1; x--) {
                ans.push_back(array[x][left]);
            }
            top++;
            left++;
            bottom--;
            right--;
        }
        return ans;
    }
};
