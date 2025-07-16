class Solution {
public:
    int cntNum(vector<int>&v,int lim){
        int ncnt=1,numsum=0;
        for(int i=0;i<v.size();i++){
            if(numsum+v[i]<=lim)numsum+=v[i];
            else{
                ncnt++;numsum=v[i];
            }
        }
        return ncnt;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int l=*max_element(nums.begin(),nums.end());
        int h=accumulate(nums.begin(),nums.end(),0);
        while(l<=h){
            int m=(l+h)/2;
            int cntnum=cntNum(nums,m);
            
            if(cntnum>k)l=m+1;
            else h=m-1;
        }
        return l;
    }
};