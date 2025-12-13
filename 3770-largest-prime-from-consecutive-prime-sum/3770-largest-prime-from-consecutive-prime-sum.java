class Solution {
    boolean isPrime(int n){
        if(n<2)return false;
        if(n%2==0)return false;
        for(int i=3;i*i<=n;i+=2){
            if(n%i==0)return false;
        }
        return true;
    }

    public int largestPrime(int n) {
        int sum=2;int res=2;
        //if(n>=2)res=2;
        for(int i=3;i+sum<=n;i++){
            if(isPrime(i)){
                sum+=i;
                if(sum<=n && isPrime(sum))res=sum;
            }
        }
        return res;
    }
}