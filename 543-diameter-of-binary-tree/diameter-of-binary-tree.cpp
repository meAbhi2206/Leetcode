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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        maxDepth(root,diameter);
        return diameter;
    }

    int maxDepth(TreeNode* root,int &diameter) {
        if(root==NULL) return 0;

        //left subtree
        int leftT=maxDepth(root->left,diameter);
        //right subtree
        int rightT=maxDepth(root->right,diameter);

        diameter=max(diameter,leftT+rightT);

        return (1+max(leftT,rightT));
    }
};