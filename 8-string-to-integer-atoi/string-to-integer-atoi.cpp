using ll=long long;
class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        if(n==0)return 0;
        ll max_int=INT_MAX;
        ll min_int=INT_MIN;
        int i=0;
        while(i<n && s[i]==' ')i++;
        if(i==n)return 0;
        int sign=1;
        if(s[i]=='+')i++;
        else if(s[i]=='-'){
            sign=-1;i++;
        }
        ll res=0;
        while(i<n && isdigit(s[i])){
            int dig=s[i]-'0';
            res=res*10+dig;
            if(sign*res<=min_int)return min_int;
            if(sign*res>=max_int)return max_int;
            i++;
        }
        return static_cast<int>(res*sign);
    }
};