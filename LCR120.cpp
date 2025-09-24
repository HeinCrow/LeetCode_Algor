#include<bits/stdc++.h>
using namespace std;
//法一：哈希表
class Solution {
public:
    int findRepeatDocument(vector<int>& documents) {
        unordered_map<int, int> map;
        int i, n = documents.size();
        for(i = 0; i < n; i++) {
            if(map.count(documents[i])){
                return documents[i];
            }
            else {
                map[documents[i]] = 1;
            }
        }
    }
};

//法二：原地交换（需要注意到序列中的数据特点——索引与元素是一对多关系）
class Solution2 {
public:
    int findRepeatDocument(vector<int>& documents) {
        int i=0, n=documents.size();
        for(i=0;i<n;i++) {
                while(documents[i] != i && documents[documents[i]] != documents[i]) {
                    swap(documents[i], documents[documents[i]]);
                }
                if(documents[i] != i) {
                    return documents[i];
                }
        }
        return -1;

    }
};
