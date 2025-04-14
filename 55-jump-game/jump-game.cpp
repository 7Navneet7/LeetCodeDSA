class Solution {
public:
    // bool canJump(vector<int>& nums) {
    //     int goal = nums.size() - 1;

    //     for (int i = nums.size() - 2; i >= 0; i--) {
    //         if (i + nums[i] >= goal) {
    //             goal = i;
    //         }
    //     }

    //     return goal == 0;        
    // }

    bool canJump(vector<int>& nums){
        int max_ind=0;
        for(int i=0;i<nums.size();i++){
            if(i>max_ind)return false;
            max_ind=max(max_ind,i+nums[i]);
        }
        return true;
    }
};