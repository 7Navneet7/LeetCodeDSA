class Solution {
public:
    // string concatHex36(int n) {
    //     long long n2 = 1LL * n * n;
    //     long long n3 = 1LL * n * n * n;

    //     // Convert to hexadecimal (uppercase)
    //     string hex_part;
    //     {
    //         stringstream ss;
    //         ss << uppercase << hex << n2;
    //         ss >> hex_part;
    //     }

    //     // Convert to base-36 (uppercase)
    //     string base36_chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    //     string base36_part;

    //     while (n3 > 0) {
    //         base36_part = base36_chars[n3 % 36] + base36_part;
    //         n3 /= 36;
    //     }

    //     return hex_part + base36_part;
    // }


    string concatHex36(int n) {
        unordered_map<int,char>mp;
        for(int i=0;i<=9;i++)mp[i]=i+'0';
        for(int i=10;i<=35;i++)mp[i]=i-10+'A';
        int n1=n*n; int n2=n*n*n;
        string res2="";
        if(n2==0)res2="0";
        while(n2>0){
            res2=mp[n2%36]+res2;
            n2/=36;
        }
        string res1="";
        if(n1==0)res1="0";
        while(n1>0){
            res1=mp[n1%16]+res1;
            n1/=16;
        }
        return res1+res2;
    }
};