//https://leetcode.com/problems/maximum-depth-of-binary-tree/submissions/931640757/
class Solution {
public:

    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        return (1 + max(left,right));
    }
};
