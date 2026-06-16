class Solution {
public:
    string processStr(string s) {
             int n = s.size();
        string ans = "";
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (ch != '#' && ch != '%' && ch != '*') {
                ans += ch;
            } else if (ch == '#') {
                ans += ans;
            } else if (ch == '%') {
                int start = 0;
                int end = ans.size() - 1;
                while(start < end){
                    swap(ans[start], ans[end]);
                    start++;
                    end--;
                }
            } else if (ch == '*') {
                if(!ans.empty()){
                    ans.pop_back();
                }
            }
        }
        return ans;
    }
};