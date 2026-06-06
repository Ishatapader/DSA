class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st; // stores indices
        int water = 0;
        int n = height.size();

        for (int i = 0; i < n; i++) {

            while (!st.empty() && height[i] > height[st.top()]) {

                int bottom = st.top();
                st.pop();

                if (st.empty())
                    break; // no left boundary

                int left = st.top();
                int right = i;

                int width = right - left - 1;
                int boundedHeight =
                    min(height[left], height[right]) - height[bottom];

                water += width * boundedHeight;
            }

            st.push(i);
        }

        return water;
    }
};