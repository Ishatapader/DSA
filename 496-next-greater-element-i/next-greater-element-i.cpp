class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

    int n = nums2.size();
    vector<int> next(n, 0);

    stack<int> s;

    int idx = n - 1;
    next[idx] = -1;
    s.push(nums2[idx]);

    for(idx = idx - 1; idx >= 0; idx--) {

        int currentElement = nums2[idx];

        while(!s.empty() && s.top() <= currentElement) {
            s.pop();
        }

        if(s.empty()) {
            next[idx] = -1;
        }
        else {
            next[idx] = s.top();
        }

        s.push(nums2[idx]);
    }

    vector<int> ans;

    for(int i = 0; i < nums1.size(); i++) {

        for(int j = 0; j < nums2.size(); j++) {

            if(nums1[i] == nums2[j]) {
                ans.push_back(next[j]);
                break;
            }
        }
    }

    return ans;
}
};