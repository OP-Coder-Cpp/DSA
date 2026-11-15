#include<bits/stdc++.h>;
using namespace std;
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        long long even=1;
        long long odd=0;
        long long ans=0;
        long long sum=0;
        long long mod=1e9+7;

        for(int i=0;i<n;i++)
        {
            sum=(sum+arr[i])%mod;
            if(sum&1)
            {
                ans=(ans+even)%mod;
                odd++;
            }
            else
            {
                ans=(ans+odd)%mod;
                even++;
            }
        }
        return (int)ans;
    }
};