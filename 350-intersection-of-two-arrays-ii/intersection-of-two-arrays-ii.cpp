class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> freq;
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++) {
            freq[nums1[i]]++;
        }
        for (int i : nums2) {
            if (freq[i] > 0) {
                ans.push_back(i);
                freq[i]--;
            }
        }
        return ans;
    }
};