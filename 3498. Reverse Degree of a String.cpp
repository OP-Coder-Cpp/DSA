#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverseDegree(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            int d=(122-int(s[i])+1)*(i+1);
            ans+=d;
        }
        return ans;
    }
};