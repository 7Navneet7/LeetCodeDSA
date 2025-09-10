class Solution {
public:
    vector<int>best;int bestDiff=INT_MAX;
    vector<int> minDifference(int n, int k) {
        vector<int>curr;
        backTrack(n,k,1,curr);
        return best;
    }
    void backTrack(int n,int k,int st,vector<int>&curr){
        if(k==1 ){
            //if(n>=st){
            curr.push_back(n);
            check(curr);
            curr.pop_back();
            //}
            return;
        }
        for(int i=st;i<=n;i++){
            if(n%i==0){
                curr.push_back(i);
                backTrack(n/i,k-1,i,curr);
                curr.pop_back();
            }
        }
    }
    void check(vector<int>curr){
        int mx=*max_element(curr.begin(),curr.end());
        int mn=*min_element(curr.begin(),curr.end());
        if(mx-mn<bestDiff){
            bestDiff=mx-mn;best=curr;
        }
    }
};