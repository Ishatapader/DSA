class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nextSmallerLeft(n);
        vector<int> nextSmallerRight(n);
        stack<int> s;
        // next smaller left
        nextSmallerLeft[0] = -1;
        s.push(0); 
        for (int i = 1; i < heights.size(); i++) {
            int currentElement = heights[i];
            while (!s.empty() && currentElement <= heights[s.top()]) {
                s.pop();
            }
            if (s.empty()) {
                nextSmallerLeft[i] = -1;
            } else {
                nextSmallerLeft[i] = s.top();
            }
            s.push(i);
        }
        while (!s.empty()) {
            s.pop();
        }
        // right next smaller
        nextSmallerRight[n - 1] = n;
        s.push(n - 1);
        for (int i = n - 2; i >= 0; i--) {
            int currentElement = heights[i];
            while (!s.empty() && currentElement <= heights[s.top()]) {
                s.pop();
            }
            if (s.empty()) {
                nextSmallerRight[i] = n;
            } else {
                nextSmallerRight[i] = s.top();
            }
            s.push(i);
        }
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int width = nextSmallerRight[i] - nextSmallerLeft[i] - 1;
            int currentArea = heights[i] * width;
            maxArea = max(maxArea, currentArea);
        }
        return maxArea;
    }
};