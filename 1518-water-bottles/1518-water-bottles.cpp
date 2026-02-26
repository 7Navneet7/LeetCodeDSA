class Solution {
public:
    int numWaterBottles(int num, int numEx) {
        int emp=0;int d=0;
        if(num>0){
                emp+=num;
                d+=num;
        }
        while(emp>=numEx){
            
            if(emp>0){
                d+=(emp/numEx);
                emp=(emp/numEx)+(emp%numEx);
            }
        }
        return d;
        
    }
};