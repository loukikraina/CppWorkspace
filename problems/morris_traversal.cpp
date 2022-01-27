class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* curr;
        vector<int> ds;
        if(!root) return ds;
        while(true){
            if(root==NULL) break;
            if(root->left==NULL) {
                ds.push_back(root->val);
                root = root->right;
                continue;
            }
            curr = root;
            root = root->left;
            while(root->right!=NULL ) {
                if(root->right==curr) break;
                root = root->right;
            }
            if(root->right) {
                root->right = NULL;
                ds.push_back(curr->val);
                root = curr->right;
            }
            else{
                root->right = curr;
                root = curr->left;
            }
        }
        return ds;
    }
};