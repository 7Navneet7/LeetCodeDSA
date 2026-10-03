class Solution {
public:
    bool isSameAfterReversals(int num) {
        if(num == 0) return true;
        string str = to_string(num);
        if(str[0] == '0' || str[str.size() - 1] == '0') return false;
        return true;
    }
};