class Solution {
public:
    int gcd(int a ,int b){
        while(b!=0){
            int temp=a%b;
            a=b;
            b=temp;
        }
        return a;
    }
    int findGCD(vector<int>& nums) {
        int min=nums[0];
        int max=nums[0];

        for(int num:nums){
            if(num<min)
                min=num;
            else if(num>max)
                max=num;
        }
        return gcd(max,min);
    }
};