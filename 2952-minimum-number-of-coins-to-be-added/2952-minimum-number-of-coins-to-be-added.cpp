class Solution {
public:
    int minimumAddedCoins(vector<int>& a, int t) {
        int mac=0;
        long long s=1;
        int i=0;
        sort(a.begin(),a.end());
        while(s<=t){
            if(i<a.size() && a[i]<=s){
                s+=a[i];
                i++;
            }
            else{
                s+=s;mac++;
            }
        }
        return mac;
    }
};