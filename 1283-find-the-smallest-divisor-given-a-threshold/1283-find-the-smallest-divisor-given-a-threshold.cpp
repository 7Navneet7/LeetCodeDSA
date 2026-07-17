class Solution {
public:
    bool candiv(vector<int>&nu,int th,int d){
        int su=0;
        for(auto it:nu){
            su+=((it+d-1)/d);
        }
        return su<=th;
    }
    int smallestDivisor(vector<int>& nu, int th) {
        int nl=nu.size();
        //search space
        int lo=1;
        int hi=*max_element(nu.begin(),nu.end());
        int ans=-1;
        while(lo<=hi){
            int md=lo+(hi-lo)/2;
            if(candiv(nu,th,md)){
                ans=md;
                hi=md-1;
            }
            else lo=md+1;
        }
        return ans;
    }
};