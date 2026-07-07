class Solution {
public:
    int climbStairs(int n) {
        //base cases
        if(n<=2)return n;
        //ways(n-2) for n=3
        int p1=1;
        int p2=2;
        int cur=0;
        for(int i=3;i<=n;i++){
            //ways(n-1)+ways(n-2)
            cur=p1+p2;
            p1=p2;
            p2=cur;

        }
        return cur;
    }
};