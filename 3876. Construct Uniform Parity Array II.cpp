#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int odd=0,even=0;
        int n=nums1.size();
        sort(nums1.begin(),nums1.end());
        vector<int> check(n);

        for(int i=0;i<n;i++){
            if(nums1[i]&1){
                odd++;
            }
            else
                even++;
            
            check[i]=odd;
        }

        if(even==n || odd==n)
            return true;
        
        for(int i=0;i<n;i++)
        {
            if(!(nums1[i]&1))
            {
                if(check[i]==0)
                    return false;
            }
        }
        return true;

    }
};