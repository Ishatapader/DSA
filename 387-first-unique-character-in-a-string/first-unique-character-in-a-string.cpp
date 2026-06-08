class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26, 0);
        queue<int> q;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            q.push(i);
            freq[ch - 'a']++;
        }
        while (!q.empty() && freq[s[q.front()] - 'a'] > 1) {
            q.pop();
        }
        if (q.empty()) {
            return -1;
        }
        return q.front();
    }
};