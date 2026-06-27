class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int l=0;unordered_map<char,int>mp;
        int len=0;
        for(int r=0;r<n;r++){
            mp[s[r]]++;
            while(mp[s[r]]>1 && l<r){
                mp[s[l]]--;l++;
            }
            len=max(len,r-l+1);
        }
        return len;
    }
};