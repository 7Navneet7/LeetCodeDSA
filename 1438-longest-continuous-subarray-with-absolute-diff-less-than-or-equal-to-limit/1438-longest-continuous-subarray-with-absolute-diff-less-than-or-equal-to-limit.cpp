class Solution {
public:
    int longestSubarray(vector<int>& nu, int k) {
        int l=0;
        int n=nu.size();
        deque<int>mxd,mnd;
        int mxl=0;
        for(int r=0;r<n;r++){
            while(!mxd.empty() && nu[mxd.back()]<=nu[r]){
                mxd.pop_back();
            }
            mxd.push_back(r);

            while(!mnd.empty()&& nu[mnd.back()]>=nu[r]){
                mnd.pop_back();
            }
            mnd.push_back(r);

            while(nu[mxd.front()]-nu[mnd.front()]>k){
                l++;
                if(mxd.front()<l)mxd.pop_front();
                if(mnd.front()<l)mnd.pop_front();
            }
            int clen=r-l+1;;
            mxl=max(mxl,clen);
        }
        return mxl;
    }
};