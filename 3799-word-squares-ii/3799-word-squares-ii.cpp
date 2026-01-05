class Solution {
public:
    // vector<vector<string>> wordSquares(vector<string>& wor) {
    //     int n=wor.size();
    //     vector<vector<string>>ans;
        
    //     for(int i=0;i<n;i++){//top
    //         string t=wor[i];
    //         for(int j=0;j<n ;j++){if(j!=i){//left
    //             string lr=wor[j];
    //             if(lr[0]==t[0]){
    //                 for(int k=0;k<n  ;k++){if(k!=i && k!=j){
    //                     string d=wor[k];
    //                     if(d[0]==lr[3]){
    //                         for(int l=0;l<n ;l++){if(l!=i && l!=j && l!=k){
    //                             string r=wor[l];
    //                             if(r[3]==d[3] && r[0]==t[0])ans.push_back({t,lr,r,d});
    //                         }
    //                         }
    //                     }
    //                 }

    //                 }
    //             }
    //         } 
    //         }
    //     }
    //     sort(ans.begin(),ans.end());
    //     return ans;
    // }


    vector<vector<string>> wordSquares(vector<string>& wor) {
        int n=wor.size();vector<vector<string>>ans;
        for(string t:wor){
            for(string d:wor){
                for(string l:wor){
                    for(string r:wor){
                        if(t!=d && t!=l && d!=l && d!=r && l!=r && r!=t){
                            if(l[0]==t[0] && l[3]==d[0] && d[3]==r[3] && r[0]==t[3]){
                                ans.push_back({t,l,r,d});
                            }
                        }
                    }
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }


};