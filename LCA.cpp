class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }
        if(root==p || root==q){
            return root;
        }
        TreeNode* LCA = lowestCommonAncestor(root->left,p,q);
        TreeNode* RCA = lowestCommonAncestor(root->right,p,q);
    if(LCA && RCA){
        return root;
    }
    if(LCA
     && RCA==NULL){
         return LCA;
     }

         return RCA;
    }
};
