class Solution {
public:
    int numWaterBottles(int nB, int nE) {
        int emp=nB;int c=nB;
        while(emp>=nE){
            c+=(emp/nE);
            emp=(emp/nE)+(emp%nE);
        }
        return c;
        
    }
};