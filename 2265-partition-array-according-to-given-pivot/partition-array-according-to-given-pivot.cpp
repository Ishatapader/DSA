class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans;
        for (int i : nums) {
            if (i < pivot) {
                ans.push_back(i);
            }
        }
        for (int j : nums) {
            if (j == pivot) {
                ans.push_back(j);
            }
        }
        for (int k : nums) {
            if (k > pivot) {
                ans.push_back(k);
            }
        }
        return ans;
    }
};