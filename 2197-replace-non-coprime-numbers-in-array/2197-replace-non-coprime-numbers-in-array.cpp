using ll=long long;
class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int n=nums.size();int i=0;
        while(i<nums.size()-1){
            if(gcd(nums[i],nums[i+1])!=1){
                int lc=lcm(nums[i],nums[i+1]);
                nums.erase(nums.begin()+i,nums.begin()+i+1);
                nums[i]=lc;i=i/2;
            }
            else i++;
        }
        return nums;
    }
    ll lcm(ll a,ll b){
        if(a==0||b==0)return 0;
        return (abs(a*b)/gcd(a,b));
    }
};