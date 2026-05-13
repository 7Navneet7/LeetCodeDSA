class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int piv) {
        vector<int>a;
        for(auto it:nums){
            if(it<piv)a.push_back(it);
        }
        for(auto it:nums){
            if(it==piv)a.push_back(it);
        }
        for(auto it:nums){
            if(it>piv)a.push_back(it);
        }
        return a;
    }
};