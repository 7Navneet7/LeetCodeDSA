#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n == 0) return tasks.size();

        // Step 1: Count frequency of each task
        vector<int> freq(26, 0);
        for (char task : tasks) {
            freq[task - 'A']++;
        }

        // Step 2: Find the maximum frequency
        int maxFreq = 0;
        for (int f : freq) {
            maxFreq = max(maxFreq, f);
        }

        // Step 3: Count how many tasks have this maximum frequency
        int maxFreqCount = 0;
        for (int f : freq) {
            if (f == maxFreq) {
                maxFreqCount++;
            }
        }

        // Step 4: Calculate the total minimum slots needed
        int minTime = (maxFreq - 1) * (n + 1) + maxFreqCount;

        // Step 5: The answer is at least the total number of tasks
        return max((int)tasks.size(), minTime);
    }
};