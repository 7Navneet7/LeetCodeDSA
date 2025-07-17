class Solution {
public:
    vector<string> partitionString(string s) {
        vector<string>ans;int n=s.size();map<string,int>mp;
        ans.push_back(string(1,s[0]));string st="";
        mp[string(1,s[0])]++;
        for(int i=1;i<n;i++){
            st+=s[i];
            if(mp[st]==0){
                mp[st]++;
                ans.push_back(st);
                st="";
            }
        }
        return ans;

    }
};