class Solution {
public:
    void heapify(int i, vector<int>& nums, int n) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int maxIdx = i;
        if (left < n && nums[left] > nums[maxIdx]) {
            maxIdx = left;
        }
        if (right < n && nums[right] > nums[maxIdx]) {
            maxIdx = right;
        }
        if (i != maxIdx) {
            swap(nums[maxIdx], nums[i]);
            heapify(maxIdx, nums, n);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(i, nums, n);
        }

        for (int i = n - 1; i >= 0; i--) {
            swap(nums[0], nums[i]);
            heapify(0, nums, i);
        }
        return nums;
    }
};