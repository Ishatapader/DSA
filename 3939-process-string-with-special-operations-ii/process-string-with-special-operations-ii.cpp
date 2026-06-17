class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();
        vector<long long> len(n);

        long long currLen = 0;

        for (int i = 0; i < n; i++) {
            char ch = s[i];

            if (ch != '#' && ch != '%' && ch != '*') {
                currLen++;
            } else if (ch == '#') {
                currLen = min(currLen * 2, (long long)4e18);
            } else if (ch == '*') {
                if (currLen > 0)
                    currLen--;
            }

            len[i] = currLen;
        }

        if (k >= currLen)
            return '.';

        for (int i = n - 1; i >= 0; i--) {

            char ch = s[i];
            long long prevLen = (i == 0 ? 0 : len[i - 1]);

            if (ch != '#' && ch != '%' && ch != '*') {
                if (k == prevLen)
                    return ch;
            } else if (ch == '#') {
                if (k >= prevLen)
                    k -= prevLen;
            } else if (ch == '%') {
                k = prevLen - 1 - k;
            }
        }

        return '.';
    }
};