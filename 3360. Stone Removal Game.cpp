#include<bits/stdc++.h>;
using namespace std;
class Solution {
public:
    bool canAliceWin(int n) {

        if(n<10)
            return false;
        n-=10;
        if(n<9)
            return true;
        int i;
        bool flag=false;
        for(i=9;i<=n;i--,flag=!flag)
            n-=i;
        
        return !flag;
    }
};