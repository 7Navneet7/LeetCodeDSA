class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>a(26,0);
        if(s.size()!=t.size())return 0;
        for(char ch:s){
            a[ch-'a']++;
        }
        for(char ch:t){
            a[ch-'a']--;
        }
        for(auto it:a){
            if(it!=0)return 0;
        }
        return 1;
    }
};