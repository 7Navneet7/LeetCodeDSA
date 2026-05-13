class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        string res="";
        auto expand=[&](int l,int r){
            while(l>=0 && r<n && s[l]==s[r]){
                l--;r++;
            }
            return s.substr(l+1,r-l-1);
        };
        for(int i=0;i<n;i++){
            string a1=expand(i,i);
            string a2=expand(i,i+1);
            if(a1.size()>res.size())res=a1;
            if(a2.size()>res.size())res=a2;

        }
        return res;
    }
};