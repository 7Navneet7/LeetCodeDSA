class Solution {
public:
    // int findJudge(int n, vector<pair<int,int>>& trust) {
        // int f;
        // int arr[n];int j=0;
        // for(auto it:trust){
        //     arr[j++]=it.first;
        // }
        // bool fg=0;
        // for(int i=1;i<=n;i++){
        //     for(int k=0;k<j;k++){
        //         if(i==arr[k]){
        //             fg=1;
        //             break;
        //         }
        //     }
        //     if(!fg){
        //         return i;
        //     }
        // }
        // return -1;




    int findJudge(int n, vector<vector<int>>& trust) {


        vector<int>arr(n+1,0);
        for(auto it:trust){
            arr[it[0]]--;arr[it[1]]++;
        }
        for(int i=1;i<=n;i++){
            if(arr[i]==n-1){
                return i;
            }
        }
        return -1;











    }
};