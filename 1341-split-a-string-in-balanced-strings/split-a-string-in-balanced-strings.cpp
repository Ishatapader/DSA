class Solution {
public:
    int balancedStringSplit(string s) {
        int count = 0;
        int substringCount = 0;
        for (int i = 0; i < s.size(); i++) {
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