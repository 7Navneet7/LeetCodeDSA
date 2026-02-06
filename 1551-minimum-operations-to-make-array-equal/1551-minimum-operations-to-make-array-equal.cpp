using ll=long long;
class Solution {
public:
    int minOperations(int n) {
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            arr[i]=(2*i)+1;
        }
        ll med=accumulate(arr.begin(),arr.end(),0ll)/n;
        ll ops=0;
        //ll med=arr[n/2];
        if(n&1){
            
            for(ll i=n/2+1;i<n;i++){
                ops+=(arr[i]-med);
            }
        }
        else{
            for(ll i=n/2;i<n;i++){
                ops+=(arr[i]-med);
            }
        }
        return ops;
    }
};