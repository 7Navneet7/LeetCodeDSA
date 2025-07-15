class Solution {
public:
    // string largestOddNumber(string num) {
    //     int n=stoi(num);int o=-1;
    //     while(n>0){
    //         o=(((n%10)&1)?max(o,n%10):o);
    //         n/=10;
    //     }
    //     return(o==-1?"":to_string(o));
    // }

    string largestOddNumber(string num){
        int n=num.size();
        for(int i=n-1;i>=0;i--){
            if((num[i]-'0')&1)
                return num.substr(0,i+1);
        }
        return "";
    }
};