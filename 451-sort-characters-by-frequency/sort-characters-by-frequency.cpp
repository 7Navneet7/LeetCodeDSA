class Solution {
public:
    static bool comp(pair<char,int>a,pair<char,int>b){
        return a.second>b.second;
    }
    string frequencySort(string s) {
        int n=s.size();unordered_map<char,int>mp;
        for(char ch:s)mp[ch]++;
        vector<pair<char,int>>par(mp.begin(),mp.end());
        sort(par.begin(),par.end(),comp);
        string ans="";
        int i=0;
        while(i<par.size()){
            while(par[i].second!=0){
                ans+=par[i].first;
                par[i].second--;
            }
            i++;
        }
        return ans;
    }
};