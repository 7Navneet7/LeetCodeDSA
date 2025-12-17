using ll=long long;
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string w;
        ss>>w;
        ll cnt=0;
        for(char c:w){
            if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')cnt++;
        }
        string ans=w;
        while(ss>>w){
            ans+=' ';
            ll cn=0;
            for(char c:w){
            if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')cn++;
            }
            if(cn==cnt)reverse(w.begin(),w.end());
            ans+=w;
        }
        return ans;
    }
};