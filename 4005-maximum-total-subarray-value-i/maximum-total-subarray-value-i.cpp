class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int max_a = INT_MIN;
        int min_a = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            max_a = max(max_a, nums[i]);
            min_a = min(min_a, nums[i]);
        }
        long long ans = (long long)k * (max_a - min_a);
        return ans;
    }
};