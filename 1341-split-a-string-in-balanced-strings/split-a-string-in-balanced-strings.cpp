class Solution {
public:
    int balancedStringSplit(string s) {
        int n = s.size();
        int count = 0;
        int substringCount = 0;
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (ch == 'R') {
                count++;
            } else {
                count--;
            }
            if (count == 0) {
                substringCount++;
            }
        }
        return substringCount;
    }
};