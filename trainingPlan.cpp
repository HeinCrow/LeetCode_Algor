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
    ListNode* trainingPlan(ListNode* head, int cnt) {
        ListNode *p = head;
        int n = 0;
        while(p != NULL) {
            n++;
            p = p->next;
        }
        int i;
        n = n-cnt;
        p = head;
        while(n--) {
            p = p->next;
        }
        return p;
        
    }
}; 