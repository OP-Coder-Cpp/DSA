#include<bits/stdc++.h>;
using namespace std;
class Solution {
public:
    string digitSum(string s, int k) {
        int n=s.size();

        string temp=s;
        string str="";
        while(n>k){
            int i=0;
            str="";
            for(;i<n;i+=k){
                int sum=0;
                for(int j=i;j<(i+k) && j<n;j++){
                    int ch=s[j]-'0';
                    sum+=ch;
                }
                str+=to_string(sum);
            }
            
            n=str.size();
            s=str;
        }
        return s;
    }
};