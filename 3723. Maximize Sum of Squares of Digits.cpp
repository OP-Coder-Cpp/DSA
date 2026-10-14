#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum>9*num) return "";

        string ans="";
        while(num-- > 0){
            int digit=min(9,sum);
            sum-=digit;
            ans+=char('0'+digit);
        }
        return sum==0? ans:"";
    }
};