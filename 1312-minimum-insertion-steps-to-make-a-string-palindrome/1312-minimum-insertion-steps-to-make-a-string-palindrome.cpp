class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        string original = s;
        reverse(s.begin(), s.end());

        return n - lcs(s, original);
    }

    int lcs(string text1, string text2) {
        int n = text1.length();

        vector<int> prev(n + 1, 0), curr(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    curr[j] = 1 + prev[j - 1];
                } else {
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }
            prev = curr;
        }

        return prev[n];
    }
};