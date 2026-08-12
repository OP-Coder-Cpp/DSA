class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int left=0;
        int ans=0;

        unordered_map<int,int> umap;

        for(int i=0;i<nums.size();i++)
        {
            umap[nums[i]]++;

            while(umap[nums[i]]>k)
            {
                umap[nums[left]]--;
                left++;
            }

            ans=max(ans,i-left+1);
        }
        return ans;
    }
};