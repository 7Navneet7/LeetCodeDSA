class Solution {
public:
    bool ceat(vector<int>&pls,int h,int md){
        long long th=0;
        for(int pl:pls){
            th+=((pl+md-1)/md);
        }
        return th<=h;
    }
    int minEatingSpeed(vector<int>& pls, int h) {
        int lo=1;
        int hi=*max_element(pls.begin(),pls.end());
        int ans=0;
        while(lo<=hi){
            int md=lo+(hi-lo)/2;
            if(ceat(pls,h,md)){
                ans=md;
                hi=md-1;
            }
            else lo=md+1;
        }
        return ans;
    }
};