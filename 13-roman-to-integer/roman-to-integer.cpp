class Solution {
public:
    int romanToInt(string s) {
        int n=s.size();
        map<char,int>mp={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'M',1000},{'D',500}};
        int res=0;
        for(int i=0;i<n-1;i++){
            if(mp[s[i]]>=mp[s[i+1]])res+=mp[s[i]];
            else res-=mp[s[i]];
        }
        res+=mp[s[n-1]];
        return res;

    }
};