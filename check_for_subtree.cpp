class Solution {
public:
bool ans;
    bool isSameTree(TreeNode* p,TreeNode* q){
        if(p==NULL && q==NULL){
            return true;
        }
        if((p==NULL && q!=NULL) || (q==NULL && p!=NULL) || (p->val!=q->val)){
            return false;
        }
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL || subRoot==NULL){
            return false;
        }
        if(root->val==subRoot->val){
          ans = isSameTree(root,subRoot);
          if(ans==true){
              return ans;
          }
        }
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
        
    }
};
