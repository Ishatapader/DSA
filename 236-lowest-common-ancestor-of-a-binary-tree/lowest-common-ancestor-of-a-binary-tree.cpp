/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool findPath(TreeNode* root, TreeNode* n, vector<TreeNode*>& path) {
        if (root == NULL) {
            return false;
        }
        path.push_back(root);
        if (root == n) {
            return true;
        }
        bool leftPath = findPath(root->left, n, path);
        bool rightPath = findPath(root->right, n, path);
        if (leftPath == true || rightPath == true) {
            return true;
        }
        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1;
        vector<TreeNode*> path2;
        findPath(root, p, path1);
        findPath(root, q, path2);
        TreeNode* lca = NULL;
        for (int i = 0, j = 0; i < path1.size() && j < path2.size(); i++, j++) {
            if (path1[i] != path2[j]) {
                return lca;
            }
            lca = path1[i];
        }
        return lca;
    }
};