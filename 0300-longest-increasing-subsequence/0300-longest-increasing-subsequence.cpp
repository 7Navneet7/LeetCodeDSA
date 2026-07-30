class Solution {
public:
    int lengthOfLIS(vector<int>& nu) {
        int n=nu.size();
        vector<int>tails;
        //the tails[i] denotes the smallest tail elem among all
        //LISs of size (i+1)
        for(auto &x:nu){
            //if a y>=x present in the tails already
            // if present, we can lower the y by uverwriting it with x to 
            // make easier for subsequent subsequences to incrtease their sizes
            auto it=lower_bound(tails.begin(),tails.end(),x);
            if(it!=tails.end()){
                int ind=it-tails.begin();
                tails[ind]=x;
            }
            else{
                tails.push_back(x);
            }
        }
        return tails.size();
    }
};