class Solution {
public:
TreeNode* BuildTree(vector<int>& inorder,int inStart,int inEnd,vector<int>& preorder,int preStart,int preEnd,map<int,int> &inorderIndex){
        if(preStart>preEnd || inStart>inEnd){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = inorderIndex[root->val];
        int numsLeft = inRoot-inStart;
        root->left= BuildTree(inorder,inStart,inRoot-1,preorder,preStart+1,numsLeft+preStart,inorderIndex);
        root->right= BuildTree(inorder,inRoot+1,inorder.size()-1,preorder,preStart+numsLeft+1,preEnd,inorderIndex);
        return root;
        
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       map<int,int> inorderIndex;
        for(int i=0;i<inorder.size();i++){
            inorderIndex[inorder[i]]=i;
        }
        TreeNode* root = BuildTree(inorder,0,inorder.size()-1,preorder,0,preorder.size()-1,inorderIndex);
        return root;
    }
};
