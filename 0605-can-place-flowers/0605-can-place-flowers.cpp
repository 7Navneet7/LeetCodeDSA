class Solution {
public:
    bool canPlaceFlowers(vector<int>& bed, int n) {
        int m=bed.size();
        for(int i=0;i<m && n>0;i++){
            if(bed[i]==0){
                bool leftOpen=(i==0||bed[i-1]==0);
                bool rightOpen=(i==m-1||bed[i+1]==0);
                if(leftOpen && rightOpen){
                    n--;
                    bed[i]=1;
                }
            }
        }
        return (n==0);
        
    }
};