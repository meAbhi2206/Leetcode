/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string s="";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();

            if(node==nullptr) s+="#,"; 
            else{
                s+=to_string(node->val)+",";
                q.push(node->left);
                q.push(node->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
    if (data.empty()) return nullptr;

    stringstream s(data);
    string str;

    getline(s, str, ',');
    
    TreeNode* root = new TreeNode(stoi(str));
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (getline(s, str, ',') && str != "#") {
            node->left = new TreeNode(stoi(str));
            q.push(node->left);
        }

        if (getline(s, str, ',') && str != "#") {
            node->right = new TreeNode(stoi(str));
            q.push(node->right);
        }
    }

    return root;
}
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));