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
    void inorder(TreeNode* root, vector<int>& nums) {
        if (root == NULL) {
            return;
        }
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }
    TreeNode* convertBST(vector<int>& nums, int st, int end) {
        if (st > end) {
            return NULL;
        }
        int mid = st + (end - st) / 2;
        TreeNode* curr = new TreeNode(nums[mid]);
        curr->left = convertBST(nums, st, mid - 1);
        curr->right = convertBST(nums, mid + 1, end);
        return curr;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nums;
        inorder(root, nums);
        return convertBST(nums, 0, nums.size() - 1);
    }
};