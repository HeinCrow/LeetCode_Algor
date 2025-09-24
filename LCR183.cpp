#include<bits/stdc++.h>
using namespace std;
//2025/9/23
//法一：单调双向队列（观察规律，动态维护历史可能最大海拔）
//法二：预处理 + 分块（统计每个元素在它所在块的前缀最小、后缀最大，望远镜中最大海拔为左端元素后缀最大和右端前缀最大中的最大）
//法三：最小堆 + 哈希表（望远镜进一个，最小堆进一个，出的不是栈顶元素就哈希表做个记录表示已出但栈中未删，栈顶元素出后新的栈顶如果之前记录过已出就出了和更新哈希表，出到栈顶元素为未出的为止）
class Solution {
public:
    vector<int> maxAltitude(vector<int>& heights, int limit) {
        int n = heights.size(), i;
        vector<int> ans;
        if(heights.empty()) {
            return ans;
        }
        deque<int> dq;//用来存放望远镜中可能历史最大海拔值，因为望远镜里右边较大的会比左边小的晚出，所以左边大的不可能成为最大海拔，所以dq为单调不增序列。        
        for(i=0;i<limit;i++) {
            while(!dq.empty() && dq.back() < heights[i]) {
                dq.pop_back();
            }
            dq.push_back(heights[i]);
        }
        ans.push_back(dq.front());
        for(i=limit;i<n;i++) {
            while(!dq.empty() && dq.back() < heights[i]) {
                dq.pop_back();
            }
            dq.push_back(heights[i]);
            if(heights[i-limit] == dq.front()) {
                dq.pop_front();
            }
            ans.push_back(dq.front());
        }
        return ans;
    }
};