class Solution {
public:
    int minOperations(string s) {
        int mx=INT_MIN;
        for(int i=0;i<s.size();i++){
            mx=max(mx,(26+'a'-s[i])%26);
        }
        return mx;
    }
};