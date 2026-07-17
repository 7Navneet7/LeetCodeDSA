class Solution {
public:
    bool canship(vector<int>&wts,int dys,int w){
        int cw=0;int d=0;
        for(auto it:wts){
            cw+=it;
            
            if(cw>w){
                cw=it;
                d++;
            }
            else if(cw==w){
                cw=0;d++;
            }
            
        }
        if(cw>0)d++;
        return d<=dys;
    }
    int shipWithinDays(vector<int>& wts, int dys) {
        int lo=*max_element(wts.begin(),wts.end());
        
        int hi=accumulate(wts.begin(),wts.end(),0);
        int ans=-1;
        while(lo<=hi){
            int md=lo+(hi-lo)/2;
            if(canship(wts,dys,md)){
                hi=md-1;
                ans=md;
            }
            else lo=md+1;
        }
        return ans;
    }
};