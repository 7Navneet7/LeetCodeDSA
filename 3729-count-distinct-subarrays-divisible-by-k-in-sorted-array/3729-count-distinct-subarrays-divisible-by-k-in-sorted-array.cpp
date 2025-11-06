class Solution {
public:
        long long numGoodSubarrays(vector<int>& A, int k) {
        unordered_map<int,long long> cnt;
        cnt[0] = 1;
        int pre = 0, n = A.size();
        long long res = 0;
        for (int a : A) {
            pre = (pre + a) % k;
            res += cnt[pre]++;
        }
        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && A[j] == A[i]) ++j;
            int l = j - i;
            for (int ll = 1; ll < l; ++ll)
                if ((1LL * ll * A[i]) % k == 0)
                    res -= (l - ll);
            i = j;
        }
        return res;
    }
};