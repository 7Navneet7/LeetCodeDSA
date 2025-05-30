class Solution {
public:
    int maxSubstrings(string word) {
        int cnt=0;
        int n=word.size();vector<int>arr(26,-1);
        for(int i=0;i<n;i++){
            int idx=word[i]-'a';
            if(arr[idx]!=-1 && i-arr[idx]+1>=4){
                cnt++;
                for(int i=0;i<26;i++)arr[i]=-1;
            }    
            else if(arr[idx]==-1)arr[idx]=i;
        }
        return cnt;
    }
};