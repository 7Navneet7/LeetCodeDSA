class Solution {
public:
    void solve(int ind,int t,vector<int>&nums,set<int>&xo,int op){
        if(t==3){
            xo.insert(op);return;
        } 
        if(ind==nums.size()){
            
            return;
        }
        // for(int i=ind;i<nums.size();i++){
        //     op=nums[i];t++;
            
        // }
        if(t<3){
            op^=nums[ind];
            solve(ind,t+1,nums,xo,op);
            op^=nums[ind];
        }
        solve(ind+1,t,nums,xo,op);
        
    }



      set<int> results;
    unordered_map<string, bool> memo;

    bool dp(int i, int count, int currXor, vector<int>& nums) {
        if (count > 3) return false;
        if (i == nums.size()) {
            if (count == 3) {
                results.insert(currXor);
                return true;
            }
            return false;
        }

        string key = to_string(i) + "," + to_string(count) + "," + to_string(currXor);
        if (memo.find(key) != memo.end()) return memo[key];

        
        bool take = dp(i , count + 1, currXor ^ nums[i], nums);
        
        bool notTake = dp(i + 1, count, currXor, nums);

        return memo[key] = take || notTake;
    }

    //void util(int ind,vector<int>&nums,)

    // int uniqueXorTriplets(vector<int>& nums) {
    //     // set<int>xo;
    //     // int n=nums.size();

        
    //     // for(int i=0;i<n;i++){
    //     //     for(int j=0;j<n;j++){
    //     //         for(int k=0;k<n;k++){
    //     //             int x=nums[i]^nums[j]^nums[k];
    //     //             xo.insert(x);
    //     //         }
    //     //     }
    //     // }

    //     // int op=0;
    //     // solve(0,0,nums,xo,op);
    //     // return xo.size();




    //     results.clear();
    //     memo.clear();
    //     dp(0, 0, 0, nums);
    //     return results.size();
    // }



    int uniqueXorTriplets(vector<int>& nums){
        int n=nums.size();
        if(n<3)return n;
        int cnt=0;int temp=n;
        while(temp>0){
            temp>>=1;
            cnt++;
        }
        return pow(2,cnt);
    }
};