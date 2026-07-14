class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int count=1;
        int i=1;
        for(;i<n;i++)
        {
            if(nums[i]==nums[i-1])
                count++;
            else
            {
                if(count>(n/2))
                    break;
                count=1;
            }
        }
        return nums[i-1];
    }
};