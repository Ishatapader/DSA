class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        vector<int> freq(100001, 0);

        int maxEven = -1;

        for (int x : nums) {
            if (x % 2 == 0) {
                freq[x]++;
                maxEven = max(maxEven, x);
            }
        }

        if (maxEven == -1) return -1;

        int ans = -1;
        int maxFreq = 0;

        for (int i = 0; i <= maxEven; i += 2) {
            if (freq[i] > maxFreq) {
                maxFreq = freq[i];
                ans = i;
            }
        }

        return ans;
    }
};