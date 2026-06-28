class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
        return false;
    }
    unordered_map<char, int> freq;


    for (int i = 0; i < s.size(); i++)
    {
        if(freq.count(s[i])){
            freq[s[i]]++;
        }
        else{
            freq[s[i]] = 1;
        }
    }
    for(int i = 0; i < t.size(); i++){
        if(freq[t[i]]){
            freq[t[i]]--;
            if(freq[t[i]] == 0){
                freq.erase(t[i]);
            }
        }
        
    }
    return freq.size() == 0;
    }
};