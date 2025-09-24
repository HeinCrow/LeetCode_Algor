#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
}; 
//双指针
//思路：想办法让两个指针同时到达交点
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1 = headA,*p2 = headB;
        while(p1 != p2) {
            p1 = p1==nullptr ? headB : p1->next;
            p2 = p2==nullptr ? headA : p2->next;
        }
        return p1;
    }
    
};