class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nu, int k) {
        int n=nu.size();
        vector<int>ans;
        deque<int>dq;
        for(int i=0;i<n;i++){
            //if(i>=k-1)ans.push_back(nu[dq.front()]);
            while(!dq.empty() && nu[dq.back()]<=nu[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            while(!dq.empty() && dq.front()<=i-k)dq.pop_front();
            if(i>=k-1)ans.push_back(nu[dq.front()]);
        }

        return ans;
    }
};