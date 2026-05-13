class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int piv) {
        //>piv:0
        //==piv:1
        //<piv :2
        vector<int>parts[3];
        for(auto it:nums){
            parts[(it<piv)+(it<=piv)].push_back(it);
        }
        vector<int>a;
        for(int i=2;i>=0;i--){
            for(auto it:parts[i])a.push_back(it);
        }
        return a;
    }
};