class Solution {
public:
    int fourSumCount(vector<int>& ar, vector<int>&br , vector<int>& cr, vector<int>& dr) {
        int ans=0;
        map<int,int>mp;
        for(int a:ar){
            for(int b:br){
                mp[a+b]++;
            }
        }

        for(int c:cr){
            for(int d:dr){
                int tar=-(c+d);
                if(mp.count(tar)){
                    ans+=mp[tar];
                }
            }
        }
        return ans;
        
    }
};