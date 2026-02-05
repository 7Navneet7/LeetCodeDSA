class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>res;
        for(int i=0;i<n;i++){
            int st=nums[i];
            int j=i+st;
            j=(j+n*(abs(j)/n+1))%n;
            res.push_back(nums[j]);
        }
        return res;
    }
};