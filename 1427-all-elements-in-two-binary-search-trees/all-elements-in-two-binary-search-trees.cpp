/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void getInorder(TreeNode* root, vector<int>& nodes) {
        if (root == NULL) {
            return;
        }
        getInorder(root->left, nodes);
        nodes.push_back(root->val);
        getInorder(root->right, nodes);
    }
    TreeNode* BSTfromSortedVector(vector<int>& merged, int st, int end) {
        if (st > end) {
            return NULL;
        }
        int mid = st + (end - st) / 2;
        TreeNode* curr = new TreeNode(merged[mid]);
        curr->left = BSTfromSortedVector(merged, st, mid - 1);
        curr->right = BSTfromSortedVector(merged, mid + 1, end);
        return curr;
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> nodes1;
        vector<int> nodes2;
        vector<int> merged;
        getInorder(root1, nodes1);
        getInorder(root2, nodes2);
        int i = 0, j = 0;
        while (i < nodes1.size() && j < nodes2.size()) {
            if (nodes1[i] < nodes2[j]) {
                merged.push_back(nodes1[i++]);

            } else {
                merged.push_back(nodes2[j++]);
            }
        }
        while (i < nodes1.size()) {
            merged.push_back(nodes1[i++]);
        }
        while (j < nodes2.size()) {
            merged.push_back(nodes2[j++]);
        }
        BSTfromSortedVector(merged, 0, merged.size() - 1);
        return merged;
    }
};