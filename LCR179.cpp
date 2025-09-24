#include<bits/stdc++.h>
using namespace std;
//双指针
//思路：与Hello里的贪心算法的最小容量问题类似。
class Solution {
public:
    vector<int> twoSum(vector<int>& price, int target) {
        int i = 0, j = price.size()-1;
        while(i <= j) {
            if (price[i]+price[j] > target){
                j--;
            }
            else if (price[i]+price[j] < target){
                i++;
            }
            else {
                return {price[i],price[j]};
            }
        }
        return {};
    }
};