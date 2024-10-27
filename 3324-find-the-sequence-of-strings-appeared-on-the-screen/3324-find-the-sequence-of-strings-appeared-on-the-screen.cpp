#include<string>
#include<vector>

class Solution {
public:
    vector<string> stringSequence(string target) {
        // vector<string>out;int n=target.size();
        // vector<string>outes;
        // for(int i=0;i<n;i++){
        //     out.push_back("a");
        //     outes.push_back(out);
        //     if(int(target[i])>int(out[i])){
        //         int ju=int(target[i])-int(out[i]);
        //         int(out[i])+=ju;
        //         outes.push_back(out);
        //     }
            
        // }
        // return outes;
        vector<string>res;
        string scr="";
        for(char t:target){
            scr+="a";res.push_back(scr);
            while(scr.back()!=t){
                scr.back()+=1;res.push_back(scr);
            }
        }
        return res;
    }
};