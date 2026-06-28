class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        vector<int> ans;
        int n = nums.size();
        for (int num : nums) {
            m[num]++;
        }
        for (auto it : m) {
            if (it.second > n / 3) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};