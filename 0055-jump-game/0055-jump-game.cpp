class Solution {
public:
    bool canJump(vector<int>& nu) {
        int n=nu.size();
        int mxj=0;
        for(int i=0;i<n;i++){
            if(mxj<i)return 0;
            mxj=max(mxj,i+nu[i]);
            if(mxj>=n)return 1;
        }
        return 1;
    }
};