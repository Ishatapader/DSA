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
    TreeNode* getInorderSuccessor(TreeNode* root) {
        while (root->left != NULL) {
            root = root->left;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) {
            return NULL;
        }
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            // root == key
            // Case 1: NO CHILD
            if (root->left == NULL && root->right == NULL) {
                return NULL;
            }
            // Case 2: 1 CHILD
            if (root->left == NULL || root->right == NULL) {
                return root->left == NULL ? root->right : root->left;
            }
            // Case 3: 2 CHILDREN
            TreeNode* IS = getInorderSuccessor(root->right);
            root->val = IS->val;
            root->right = deleteNode(root->right, IS->val);
            return root;
        }
        return root;
    }
};