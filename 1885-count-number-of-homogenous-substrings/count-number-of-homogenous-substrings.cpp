using ll=long long;
class Solution {
public:
    int countHomogenous(string s) {
        int n=s.size();ll res=0;
        int l=0;
        for(int r=0;r<n;r++){
            if(s[l]==s[r]){
                res+=(r-l+1);
            }
            else{
                res+=1;l=r;
            }
        }
        res=res%(1000000007);
        return (int)res;

    }
};