class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int count=0;
        int xr=0;

        for(int num : nums){
            xr^=num;
            if(num!=0)
                count=num;
        }
        if(xr!=0)
            return nums.size();
        else
            if(count!=0)
                return nums.size()-1;
        
        return 0;
    }
};