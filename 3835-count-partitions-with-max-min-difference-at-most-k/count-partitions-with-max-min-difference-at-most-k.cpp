class Solution {
public:
    int countPartitions(vector<int>& A, int k) {
        int n = A.size(), mod = 1e9 + 7;
        vector<int> dp(n + 1, 0); dp[0] = 1;
        vector<int> acc(n + 2, 0); acc[1] = 1;

        deque<int> minq, maxq;
        for (int i = 0, j = 0; j < n; ++j) {
            while (!maxq.empty() && A[j] > A[maxq.back()])
                maxq.pop_back();
            maxq.push_back(j);
            while (!minq.empty() && A[j] < A[minq.back()])
                minq.pop_back();
            minq.push_back(j);
            while (A[maxq.front()] - A[minq.front()] > k) {
                ++i;
                if (minq.front() < i)
                    minq.pop_front();
                if (maxq.front() < i)
                    maxq.pop_front();
            }

            dp[j + 1] = (acc[j + 1] - acc[i] + mod) % mod;
            acc[j + 2] = (acc[j + 1] + dp[j + 1]) % mod;
        }

        return dp[n];
    }
};