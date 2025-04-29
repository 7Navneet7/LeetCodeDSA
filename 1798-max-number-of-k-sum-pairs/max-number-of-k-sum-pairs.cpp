class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int ops=0;
        int j=nums.size()-1;int i=0;
        sort(nums.begin(),nums.end());
        while(i<j){
            int sum=nums[i]+nums[j];
            if(sum<k)i++;
            else if(sum>k)j--;
            else{
                ops++;
                //nums.erase(nums.begin()+i);nums.erase(nums.begin()+j);
                i++;j--;
            }
        }
        return ops;
    }
};