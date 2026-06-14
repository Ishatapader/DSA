/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
pair<int, int> Diam2(TreeNode* root){ //0(n) - Optimal Solution
    //so this function will call for each node n. so n * O(1){constant works} = O(n).
if(root == NULL){
    return make_pair(0,0);
}

    //pair(diameter, Height)
    pair<int, int> leftInfo = Diam2(root -> left); //LD, LH
    pair<int, int> rightInfo = Diam2(root -> right); //RD, RH
    int currDiam = leftInfo.second + rightInfo.second;
    int finalDiam = max(currDiam, max(leftInfo.first, rightInfo.first));
    int finalHeight = max(leftInfo.second, rightInfo.second) + 1;
    return make_pair(finalDiam, finalHeight); 
}
    int diameterOfBinaryTree(TreeNode* root) {
       return  Diam2(root).first;
    }
};