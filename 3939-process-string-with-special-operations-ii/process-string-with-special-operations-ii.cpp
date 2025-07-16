using ll=long long;
class Solution {
public:
    char processStr(string s, ll k) {
        ll n=s.size();ll len=0;
        for(auto ch:s){
            if(islower(ch)){
                len++;
            }
            else if(ch=='*' &&len>0)len--;
            else if(ch=='#')len*=2;
            
        }
        if(k>=len)return '.';
        for(ll i=n-1;i>=0;i--){
            if(islower(s[i])){
                if(len-1==k)return s[i];
                len--;
            }
            else if(s[i]=='*')len++;
            else if(s[i]=='#'){
                len/=2;
                if(k>=len)k-=len;
            }
            else if(s[i]=='%') k=len-1-k;
        }
        return '.';
    }
};