class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char,int>mp;int res=0;
        int mmf=0;int j=0;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
            mmf=max(mmf,mp[s[i]]);
            while(i-j+1-mmf>k){
                mp[s[j]]--;
                j++;
            }
            res=max(res,i-j+1);
        }
        return res;
    }
};