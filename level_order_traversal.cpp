class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> result;
            int size= q.size();
           
            for(int i=0;i<size;i++){
                TreeNode* front = q.front();
                result.push_back(front->val);
                q.pop();

                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }

            }
            ans.push_back(result);
        }
        return ans;
    }
};
