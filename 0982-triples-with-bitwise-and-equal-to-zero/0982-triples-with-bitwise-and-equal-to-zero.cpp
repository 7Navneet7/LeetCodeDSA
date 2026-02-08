class Solution {
public:
    int countTriplets(vector<int>& nums) {
        const int MAXM = 1 << 16;   // 65536
        vector<int> freq(MAXM, 0);

        int n = nums.size();

        // Step 1: pair AND frequency
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                freq[nums[i] & nums[j]]++;
            }
        }

        // Step 2: count triplets
        int ans = 0;
        for (int k = 0; k < n; k++) {
            for (int mask = 0; mask < MAXM; mask++) {
                if ((mask & nums[k]) == 0) {
                    ans += freq[mask];
                }
            }
        }

        return ans;
    }
};
