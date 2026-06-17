class Solution {
public:
    char processStr(string s, long long k) {

        vector<long long> len(s.size());
        long long cur = 0;

        // Calculate lengths
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '#')
                cur *= 2;
            else if (s[i] == '*') {
                if (cur > 0) cur--;
            }
            else if (s[i] != '%')
                cur++;

            len[i] = min(cur, (long long)4e18);
        }

        if (k >= cur) return '.';

        // Work backwards
        for (int i = s.size() - 1; i >= 0; i--) {

            long long prev = (i == 0 ? 0 : len[i - 1]);

            if (s[i] == '#') {
                if (k >= prev) k -= prev;
            }
            else if (s[i] == '%') {
                if (prev) k = prev - 1 - k;
            }
            else if (s[i] == '*') {
                continue;
            }
            else {
                if (k == prev) return s[i];
            }
        }

        return '.';
    }
};