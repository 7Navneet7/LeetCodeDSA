class Solution {
public:
    // vector<int> majorityElement(vector<int>& nums) {
    //     set<int>st;
    //     int cnt=0,ele;
    //     int n=nums.size();
    //     sort(nums.begin(),nums.end());
    //     for(int i=0;i<n;i++){
    //         if(cnt==0){
    //             cnt=1;ele=nums[i];
    //         }
    //         else if(nums[i]==ele){
    //             cnt++;
    //             if(cnt>n/3)st.insert(ele);
    //         }    
    //         else cnt--;
    //     }
    //     int cnt1=0;
    //     for(int i=0;i<nums.size();i++){
    //         cnt1+=(nums[i]==ele?1:0);
    //     }
    //     if(cnt1>n/3)st.insert(ele);
    //     int ele2;cnt=0;
    //     for(int i=n-1;i>=0;i--){
    //         if(cnt==0){
    //             cnt=1;ele2=nums[i];
    //         }
    //         else if(nums[i]==ele2){
    //             cnt++;
    //             if(cnt>n/3)st.insert(ele2);
    //         }    
    //         else cnt--;   
    //     }
    //     cnt1=0;
    //     for(int i=0;i<nums.size();i++){
    //         cnt1+=(nums[i]==ele2?1:0);
    //     }
    //     if(cnt1>n/3)st.insert(ele2);
    //     vector<int>ans(st.begin(),st.end());
    //     return ans;
        
    // }


    // vector<int> majorityElement(vector<int>& nums) {
    //     int n=nums.size();
    //     map<int,int>mp;
    //     for(int x:nums)mp[x]++;vector<int>ans;
    //     for(auto[key,val]:mp){
    //         if(val>n/3)ans.push_back(key);
    //     }
    //     return ans;
    // }


    vector<int> majorityElement(vector<int>& nums){
        int n=nums.size();
        int a=-1,b=-1;
        int cnt_a=0,cnt_b=0;
        for(int i=0;i<n;i++){
            if(nums[i]==a)cnt_a++;
            else if(nums[i]==b)cnt_b++;
            else if(cnt_a==0){cnt_a++;a=nums[i];}
            else if(cnt_b==0){cnt_b++;b=nums[i];}
            else{cnt_a--;cnt_b--;}

        }
        cnt_a=0,cnt_b=0;
        for(int x:nums){
            if(x==a)cnt_a++;
            else if(x==b)cnt_b++;
        }
        vector<int>ans;
        if(cnt_a>n/3)ans.push_back(a);
        if(cnt_b>n/3)ans.push_back(b);
        return ans;
    }
};