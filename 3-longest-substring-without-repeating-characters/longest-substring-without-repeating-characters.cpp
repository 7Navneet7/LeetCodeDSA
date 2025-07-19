class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        set<char>st;int l=0,r=0,maxi=0;
        while(r<n){
            if(st.find(s[r])==st.end()){
                st.insert(s[r]);
                maxi=max(maxi,r-l+1);
                r++;

            }
            else{
                st.erase(s[l]);l++;
            }
        }
        return maxi; 
    }
};