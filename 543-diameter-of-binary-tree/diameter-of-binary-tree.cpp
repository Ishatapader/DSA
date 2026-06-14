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
    pair<int, int> Diam2(TreeNode* root) {
        if (root == NULL) {
            return make_pair(0, 0);
        }

        pair<int, int> leftInfo = Diam2(root->left);
        pair<int, int> rightInfo = Diam2(root->right);
        int currDiam = leftInfo.second + rightInfo.second;
        int finalDiam = max(currDiam, max(leftInfo.first, rightInfo.first));
        int finalHeight = max(leftInfo.second, rightInfo.second) + 1;
        return make_pair(finalDiam, finalHeight);
    }
    int diameterOfBinaryTree(TreeNode* root) { return Diam2(root).first; }
};