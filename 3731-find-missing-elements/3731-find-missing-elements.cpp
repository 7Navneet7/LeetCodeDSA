class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        int mn=*min_element(nums.begin(),nums.end());
        int mx=*max_element(nums.begin(),nums.end());
        vector<int>ans;
        for(int i=mn+1;i<=mx-1;i++){
            if(find(nums.begin(),nums.end(),i)==nums.end()){
                ans.push_back(i);
            }
        }
        return ans;
        
    }
};