class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> ans;
        int m = s.size();
        for (int i = 0; i < m; i++) {
            int ptr1 = i;
            int count = 0;
            int row = startPos[0];
            int col = startPos[1];
            while (ptr1 < m) {
                if (s[ptr1] == 'L')
                    col--;
                else if (s[ptr1] == 'R')
                    col++;
                else if (s[ptr1] == 'U')
                    row--;
                else
                    row++;
                if (row >= 0 && row < n && col >= 0 && col < n)
                    count++;
                else
                    break;
                ptr1++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};