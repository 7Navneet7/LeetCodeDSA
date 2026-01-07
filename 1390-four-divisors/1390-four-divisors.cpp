class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int tosum=0;
        for(int x:nums){
            int cnt=0,sum=0;
            for(int i=1;i<=sqrt(x);i++){
                if(x%i==0){
                    int j=x/i;
                    cnt++;sum+=i;
                    if(j!=i){
                        cnt++;sum+=j;
                    }
                }
                if(cnt>4)break;
            }
            if(cnt==4)tosum+=sum;
        }
        return tosum;
    }
};