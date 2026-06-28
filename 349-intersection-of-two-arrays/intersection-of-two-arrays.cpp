class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s2;
        vector<int>ans;
        for (int i = 0; i < nums1.size(); i++) {
            s2.insert(nums1[i]);
        }
        for (int i : nums2) {
            if (s2.find(i) != s2.end()) {
                ans.push_back(i);
                s2.erase(i);
            }
        }
        return ans;
    }
};