using ll =long long;
class Solution {
public:
    long long sumAndMultiply(int n) {
        ll sum=0;string s="";
        if(n==0)return 0;
        while(n>0){
            ll r=n%10;
            if(r!=0)s+=(r+'0');
            sum+=r;
            n/=10;
        }
        reverse(s.begin(),s.end());
        return (stoll(s))*sum;
    }
};