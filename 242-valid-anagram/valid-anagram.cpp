class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> s_freq;
        unordered_map<char, int> t_freq;
        int s_size = s.size();
        int t_size = t.size();
        if (s_size != t_size) {
            return false;
        }

        for (int i = 0; i < s_size; i++) {
            s_freq[s[i]]++;
            t_freq[t[i]]++;
        }
        for (auto it : s_freq) {
            if (t_freq[it.first] != it.second) {
                return false;
            }
        }
        return true;
    }
};