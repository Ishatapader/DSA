class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>mp;
        vector<vector<string>>ans;
        for(auto &word: strs){
            vector<int>freq(26,0);
            for(int i = 0; i < word.size(); i++){
                freq[word[i] - 'a']++;
            }
            string key = "";
            for(int i = 0; i < freq.size(); i++){
                key += to_string(freq[i])+"#";
            }
            mp[key].push_back(word);
        }
        for(auto &it: mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};