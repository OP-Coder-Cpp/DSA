#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countRotations(string s, int k) {
        int n=s.size();
        int ans=0;

        for(int i=0;i<n;i++){
            int score=0;

            for(int j=0;j<n-1;j++)
            {
                int curr=(i+j)%n;
                int next=(i+j+1)%n;

                if(s[curr]==s[next])
                    score++;
            }
            if(score==k)
                ans++;
        }
        return ans;
    }
};