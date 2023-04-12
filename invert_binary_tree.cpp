class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        
        if(root==NULL){
            return NULL;
        }
        TreeNode* temp;


        // if(root->left==NULL && root->right!=NULL){
        //     root->left = root->right;
        // }else if(root->right==NULL && root->left!=NULL){
        //     root->right = root->left;
        // }else{
            temp = root->left;
            root->left = root->right;
            root->right = temp;
        // }
        invertTree(root->left);
        invertTree(root->right);

        return root;
        
    }
};
