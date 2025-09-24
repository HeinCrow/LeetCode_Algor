#include<bits/stdc++.h>
using namespace std;
//2025/9/23
//双向队列
//思路和 LCR183 相似
//T O(1), S O(n);
//时间复杂度解释：这里的时间复杂度为所有操作的均摊时间复杂度，把q的总入队数 n 视作数据规模，虽然一次add操作的最差时间复杂度为 O(n), 但因为 max 的总出队数 <= n, 所以平均一次add操作 max 的出队数 <= n/n = 1, 平均时间复杂度为 O(1)
class Checkout {
    queue<int> q;
    deque<int> max;//动态维护 q 中历史可能最大值, 右边的元素是左边的元素出队后队列中的最大值，max是个单调不增序列。
public:
    Checkout() {
        
    }
    
    int get_max() {
        if(q.empty()) {
            return -1;
        }
        return max.front();
    }
    
    void add(int value) {
        q.push(value);
        while(!max.empty() && max.back() < value) {
            max.pop_back();
        }
        max.push_back(value);
    }
    
    int remove() {
        if(q.empty()) {
            return -1;
        }
        int k = q.front();
        q.pop();
        if(k == max.front()) {
            max.pop_front();
        }
        return k;
    }
};