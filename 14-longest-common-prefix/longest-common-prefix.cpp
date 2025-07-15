class Solution {
public:
    // string longestCommonPrefix(vector<string>& strs) {
    //     int n=strs.size();
    //     int j=-1;
    //     for(int i=0;i<n-1;i++){
    //         if(strs[i][j+1]!=strs[i+1][j+1]){
    //             break;
    //         }
    //         if(i==n-2)j++;
    //     }
    //     return (j!=-1?strs[0].substr(0,j+1):"");
    // }


    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        for(int j=0;j<strs[0].size();j++){
            char ch=strs[0][j];
            for(int i=1;i<n;i++){
                if(j>=strs[i].size()||strs[0][j]!=strs[i][j]){
                    return strs[0].substr(0,j);
                }
            }
        }
        return strs[0];
    }    
};