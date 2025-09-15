class Solution {
public:
    int canBeTypedWords(string text, string brok) {
        int n=text.size();
        int m=brok.size();int cnt=1;
        for(int i=0;i<n;i++){
            if(text[i]==' ')cnt++;
        }
        bool f=0;
        for(int i=0;i<n;i++){
            if(brok.find(text[i])!=string::npos && !f){cnt--;f=1;}
            if(text[i]==' ')f=0;
        }
        return cnt;
    }
};