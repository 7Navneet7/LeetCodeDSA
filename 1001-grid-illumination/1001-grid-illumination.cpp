class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        unordered_map<int, int> row_cnt, col_cnt, diag_cnt, anti_diag_cnt;
        unordered_set<long long> lamp_set;

        // Initialize lamps
        for (const auto& lamp : lamps) {
            int r = lamp[0], c = lamp[1];
            long long code = (long long)r * n + c;
            if (lamp_set.find(code) == lamp_set.end()) {
                lamp_set.insert(code);
                row_cnt[r]++;
                col_cnt[c]++;
                diag_cnt[r - c]++;
                anti_diag_cnt[r + c]++;
            }
        }

        vector<int> ans;
        for (const auto& q : queries) {
            int r = q[0], c = q[1];
            
            // Check if illuminated
            if (row_cnt[r] > 0 || col_cnt[c] > 0 || 
                diag_cnt[r - c] > 0 || anti_diag_cnt[r + c] > 0) {
                ans.push_back(1);
            } else {
                ans.push_back(0);
            }

            // Turn off 3x3 adjacent lamps
            for (int i = r - 1; i <= r + 1; ++i) {
                for (int j = c - 1; j <= c + 1; ++j) {
                    if (i < 0 || i >= n || j < 0 || j >= n) continue;
                    
                    long long code = (long long)i * n + j;
                    if (lamp_set.erase(code)) { // Returns 1 if lamp was present
                        row_cnt[i]--;
                        col_cnt[j]--;
                        diag_cnt[i - j]--;
                        anti_diag_cnt[i + j]--;
                    }
                }
            }
        }

        return ans;
    }
};