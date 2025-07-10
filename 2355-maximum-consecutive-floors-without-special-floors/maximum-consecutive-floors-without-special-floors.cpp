class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        int n=special.size();
        sort(special.begin(),special.end());
        int diff=max(special[0]-bottom,top-special[n-1]);
        for(int i=0;i<n-1;i++){
            int d=special[i+1]-special[i]-1;
            diff=max(diff,d);
        }
        return diff;
    }
};