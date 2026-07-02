class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;
        for (string word : strs) {
            string key = word;
            sort(key.begin(), key.end());
            mp[key].push_back(word);
        }
        for (auto it : mp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};