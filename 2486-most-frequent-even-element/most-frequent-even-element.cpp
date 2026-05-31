class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int ans = -1;
        int maxFreq = 0;

        for (int i = 0; i < nums.size();) {
            int cnt = 1;

            while (i + cnt < nums.size() && nums[i] == nums[i + cnt]) {
                cnt++;
            }

            if (nums[i] % 2 == 0 && cnt > maxFreq) {
                maxFreq = cnt;
                ans = nums[i];
            }

            i += cnt;
        }

        return ans;
    }
};