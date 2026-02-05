using ll=long long;
class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& tar) {
        vector<vector<ll>>aa(2),bb(2);
        for(ll a:nums)aa[a%2].push_back(a);
        for(ll a:tar)bb[a%2].push_back(a);
        ll res=0;
        sort(aa[0].begin(),aa[0].end());
        sort(aa[1].begin(),aa[1].end());
        sort(bb[0].begin(),bb[0].end());
        sort(bb[1].begin(),bb[1].end());
        for(ll i=0;i<aa[0].size();i++){
            res+=(abs(aa[0][i]-bb[0][i]))/2;
        }
        for(ll i=0;i<bb[1].size();i++){
            res+=(abs(bb[1][i]-aa[1][i]))/2;
        }
        return res/2;

        
    }
};