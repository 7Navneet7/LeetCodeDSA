class Solution {
public:
    const int maxi=200005;
    const int logs=18;
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        // st[i]denotes the max element in range starting from i having size 3
        vector<vector<int>>st(n,vector<int>(logs));
        vector<int>log(n+1);
        log[1]=0;
        for(int i=2;i<=n;i++)log[i]=log[i/2]+1;
        for(int i=0;i<n;i++){
            st[i][0]=nums[i];
        }
        for(int j=1;j<=logs;j++){
            for(int i=0;i+(1<<(j))<=n;i++){
                st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
            }
        }
        int j=log[k];vector<int>ans;
        for(int i=0;i<=n-k;i++){
            ans.push_back(max(st[i][j],st[i+k-(1<<j)][j]));

        }
        return ans;

    }
};