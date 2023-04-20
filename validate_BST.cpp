class Solution {
public:
    bool isBST(TreeNode* root,long minLimit,long maxLimit){
        if(root==NULL){
            return true;
        }
        if(root->val <= minLimit || root->val >= maxLimit){
            return false;
        }
        return isBST(root->left,minLimit,root->val) && isBST(root->right,root->val,maxLimit);
    }

    bool isValidBST(TreeNode* root) {
        // if(root->left==NULL || root->right==NULL){
        //     if(root->left!=NULL && root->left->val>=root->val){
        //         return false;
        //     } if(root->right!=NULL && root->right->val<=root->val){
        //         return false;
        //     }else{
        //         return true;
        //     }
        // }
      
     
      
        return  isBST(root,LONG_MIN,LONG_MAX);
        // bool getRight = isRightBST(root->right,root->val,limit.second);
    }
};
