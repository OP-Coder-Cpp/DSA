#include<bits/stdc++.h>;
using namespace std;
class Solution {
public:
    bool checkString(string s) {
        bool check_notB=true;

        for(char ch: s){
            if(ch=='a' && check_notB)
                continue;
            else if(ch=='a' && !check_notB)
                return false;
            else if(ch=='b' && check_notB)
            {
                check_notB=false;
            }
        }
        return true;
    }
};