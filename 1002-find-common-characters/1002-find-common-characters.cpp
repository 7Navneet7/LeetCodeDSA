class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string>ans;
        int n=words.size();
        string st=words[0];
        for(int i=0;i<st.size();i++){
            char s=st[i];bool f=1;
            for(int j=1;j<n;j++){
                string s2=words[j];
                // for(int k=0;k<s2.size();k++){
                //     if(s2[k]==s){break;}
                // }
                int k=0;
                while(k<s2.size()){
                    if(s2[k]!=s)k++;
                    else break;
                }
                if(k==s2.size()){f=0;break;}
                else words[j][k]='&';

            }
            if(f){
                string s3="";s3+=s;
                ans.push_back(s3);
            }    
        }
        return ans;
    }
};