class Node {
public:
    unordered_map<char, Node*> children;
    bool endOfWord;
    vector<string> words;
    Node() { endOfWord = false; }
};
class Trie {
    Node* root;

public:
    Trie() {
        root =
            new Node(); // empty node for root and its endofword would be false
    }

    void insert(string key, string original) {

        Node* temp = root;

        for (char ch : key) {

            if (temp->children.count(ch) == 0)
                temp->children[ch] = new Node();

            temp = temp->children[ch];
        }

        temp->endOfWord = true;
        temp->words.push_back(original);
    }

    void dfsHelper(Node* root, vector<vector<string>>& ans) {
        if (root->endOfWord) {
            ans.push_back(root->words);
        }
        for (auto child : root->children) {
            dfsHelper(child.second, ans);
        }
    }
    void dfs(vector<vector<string>>& ans) { dfsHelper(root, ans); }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        Trie trie;
        vector<vector<string>> ans;
        for (string word : strs) {
            string key = word;
            sort(key.begin(), key.end());
            trie.insert(key, word);
        }
        trie.dfs(ans);
        return ans;
    }
};