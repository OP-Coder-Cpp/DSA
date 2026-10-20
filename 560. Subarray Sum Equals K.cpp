#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<long long, int> umap;
        umap[0]=1;
        long long prefixSum=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            prefixSum+=nums[i];

            long long need=prefixSum-k;
            if(umap.count(need)){
                ans+=umap[need];
            }
            umap[prefixSum]++;
        }
        return ans;
    }
};