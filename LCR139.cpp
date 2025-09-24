#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
}; 

class Solution {
public:
    vector<int> trainingPlan(vector<int>& actions) {
        int i,j=actions.size()-1;
        while(i<j) {
            while(actions[i]%2 != 0 && i<j) {
                i++;
            }
            while(actions[j]%2 != 1 && i<j) {
                j--;
            }
            swap(actions[i],actions[j]);
        }      
        return actions;

    }
};