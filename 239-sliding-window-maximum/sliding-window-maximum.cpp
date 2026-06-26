class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int, int>>deq; 
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            while (!deq.empty() && deq.front().second <= (i - k)) {
                deq.pop_front();
            }
            while(!deq.empty() && deq.back().first <= nums[i]){
                deq.pop_back();
            }
            deq.push_back({nums[i], i});
            if(i >= k - 1){
            ans.push_back(deq.front().first);
            }
        }
        return ans;
    }
};