class Solution {
public:
    int closestToTarget(vector<int>& arr, int tar) {
        int n=arr.size();
        int ans=1e9;
        set<int>st;
        for(int i=0;i<n;i++){
            set<int>nst;
            nst.insert(arr[i]);
            for(auto it:st){
                nst.insert(it &arr[i]);
            }
            for(auto it:nst){
                ans=min(ans,abs(tar-it));
            }
            st=nst;
        }
        return ans;
    }
};