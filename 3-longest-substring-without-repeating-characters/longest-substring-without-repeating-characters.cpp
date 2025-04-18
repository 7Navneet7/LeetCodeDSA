class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int j=0;
        //vector<int>cnt(128,0);
        int cnt[128]={};
        int ans=0;
        for(int i=0;i<s.size();i++){
            cnt[s[i]]++;
            while(cnt[s[i]]>1){
                cnt[s[j]]--;
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};