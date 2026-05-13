class Solution {
public:
    int minCostToMoveChips(vector<int>& post) {
        int n=post.size();
        int od=0;
        for(auto it:post){
            if(it&1)od++;
        }
        return min(od,n-od);
    }
};