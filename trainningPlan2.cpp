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
    ListNode* trainningPlan(ListNode* l1, ListNode* l2) {
        ListNode *l;
        if(l1 == NULL && l2 == NULL) {
            return NULL;
        }
        if(l1 == NULL) {
            return l2;
        }
        if(l2 == NULL) {
            return l1;
        }
        if(l1->val < l2->val) {
            l = l1;
            l1 = l1->next;
        }
        else{
            l = l2;
            l2 = l2->next;
        }
        ListNode *p = l;
        while(l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val){
                p->next = l1;
                l1 = l1->next;
                p = p->next;
            }
            else {
                p->next = l2;
                l2 = l2->next;
                p = p->next;
            }
        }
        if(l1 != NULL) {
            p->next = l1;
        }
        if(l2 != NULL) {
            p->next = l2;
        }
        return l;

        
    }
};