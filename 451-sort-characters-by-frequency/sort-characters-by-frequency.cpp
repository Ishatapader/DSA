class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (int i = 0; i < s.size(); i++) {
            freq[s[i]]++;
        }
        sort(s.begin(), s.end(),
             [&](char a, char b) { 
                if(freq[a] == freq[b]){
                    return a > b;
                }
                return freq[a] > freq[b]; });
        return s;
    }
};