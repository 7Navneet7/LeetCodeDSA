class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& ar) {
        int al=ar.size();
        unordered_map<int,int>mp;
        vector<int>br=ar;
        sort(br.begin(),br.end());
        int r=1;
        for(auto &it:br){
            if(!mp.count(it)){
                mp[it]=r++;
            }
        }
        for(auto &it:ar){
            it=mp[it];
        }
        return ar;
    }
};