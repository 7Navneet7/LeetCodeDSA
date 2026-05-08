class Solution {
    boolean isPrime(int n){
        if(n==1)return false;
            if(n==2)return true;
        for(int i=2;i<=Math.sqrt(n);i++){
            
            if(n%i==0)return false;
        }
        return true;
    }
    public int sumOfPrimesInRange(int n) {
        String n1=Integer.toString(n);
        StringBuilder sb=new StringBuilder(n1);
        n1=sb.reverse().toString();
        int nu=Integer.parseInt(n1);
        int mx=Math.max(nu,n);int mn=Math.min(nu,n);
        int c=0;
        for(int i=mn;i<=mx;i++){
            if(isPrime(i))c+=i;
        }
        return c;
    }
}