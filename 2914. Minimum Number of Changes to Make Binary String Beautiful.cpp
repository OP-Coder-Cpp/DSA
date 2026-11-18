#include<bits/stdc++.h>;
using namespace std;
class Solution {
public:
    int minChanges(string s) {
        int n=s.size();

        int left=0,right=1;
        int ans=0;
        for(;right<n;right+=2,left+=2){
            if(s[left]!=s[right])
                ans++;
        }
        return ans;
    }
};