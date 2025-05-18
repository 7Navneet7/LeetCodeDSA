class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int>vec(n);
        for(int i=0;i<n;i++){
            int num=nums[i];
            int su=0;
            while(num>0){
                su+=num%10;
                num/=10;
            }
            vec[i]=su;
        }
        for(int i=0;i<n;i++){
            if(i==vec[i])return i; 
        }
        return -1;
    }
};