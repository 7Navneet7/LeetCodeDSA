
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        bool u0=0,u1=0,u2=0;
        int st=0;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1])return 0;
            if(st==0){
                if(nums[i]<nums[i+1])u0=1;
                else{
                    if(!u0)return 0;
                    else{
                        u1=1;st=1;
                    }
                }
            }
            else if(st==1){
                if(nums[i]>nums[i+1])u1=1;
                else{
                    st=2;
                    u2=1;
                }
            }
            else{
                if(nums[i]<nums[i+1])u2=1;
                else return 0;
            }
        }
        return (u0&u1&u2);
    }
};
