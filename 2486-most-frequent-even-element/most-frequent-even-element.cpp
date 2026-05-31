class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(100001, 0);
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0) {
                freq[nums[i]]++;
            }
        }
        int max_count = 0;
        int ans = -1;
        for (int i = 0; i < 100000; i+=2) {
            if (freq[i] > max_count) {
                max_count = freq[i];
                ans = i;
            }
        }
        return ans;
    }
};