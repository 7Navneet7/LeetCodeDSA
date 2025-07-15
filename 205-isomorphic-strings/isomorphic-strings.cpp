class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char>mp;int n=s.size();vector<bool>a(1000);
        for(int i=0;i<n;i++){
            if(mp[s[i]]=='\0' && !a[t[i]]){
                mp[s[i]]=t[i];
                a[t[i]]=1;
            }
            else{
                if(mp[s[i]]!=t[i])return false;
            }
        }
        return true;
    }
};