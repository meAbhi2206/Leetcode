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
    bool isBalanced(TreeNode* root) {
        return (maxDepth(root)!=-1);
    }

    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;

        //left subtree
        int leftT=maxDepth(root->left);
        if(leftT==-1) return -1;
        //right subtree
        int rightT=maxDepth(root->right);
        if(rightT==-1) return -1;

        if(abs(leftT-rightT)>1) return -1;

        return (1+max(leftT,rightT));
    }
};