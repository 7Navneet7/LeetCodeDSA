class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int>smp,tmp;
        if(s.size()!=t.size())return false;
        int n=s.size();
        for(int i=0;i<n;i++){
            smp[s[i]]++;tmp[t[i]]++;
        }
        for(auto&[key,val]:smp){
            if(tmp[key]!=val)return false;
        }
        return true;
    }
};