#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseMessage(string message) {
        int i,j=message.size()-1;
        string ans;
        if(j < 0) {
            return ans;
        }
        while(1) {
            while(j >= 0 && message[j] == ' ') {
                j--;
            }
            if(j < 0) {
                return ans;
            }
            i = j;
            while(i >= 0 && message[i] != ' ') {
                i--;
            }
            if(ans.size() != 0) {
                ans.append(" " + message.substr(i+1, j-i));   
            }else {
                ans.append(message.substr(i+1, j-i));
            }
            j = i; 
            
        }
        return ans;
        
    }

};