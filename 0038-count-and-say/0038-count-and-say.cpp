class Solution {
public:
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        else{

        string str=countAndSay(n-1);
        string str2;
        for(int i=0;i<str.length();i++){
            int c=1;int item=str[i];
            while(i<str.length()-1 && str[i]==str[i+1]){
                c++;
                i++;
            }
            // str2.push_back(c);
            // str2.push_back(str[i]);
            str2+=to_string(c);
            str2+=str[i];
           
        }
    return str2;
    }
        
    }
};