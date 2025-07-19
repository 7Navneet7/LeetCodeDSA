class Solution {
public:
    int expandCenter(string s,int l,int r){
        while(l>=0 && r<s.size()&&s[l]==s[r]){
            l--;r++;
        }
        return r-l-1;
    }
    string longestPalindrome(string s) {
        int n=s.size();
        if(s.empty())return "";
        int st=0,end=0;
        for(int i=0;i<n;i++){
            int odd=expandCenter(s,i,i);
            int even=expandCenter(s,i,i+1);
            int max_len=max(even,odd);
            if(max_len>end-st){
                st=i-(max_len-1)/2;
                end=i+(max_len/2);
            }
        }
        return s.substr(st,end-st+1);
    }
};