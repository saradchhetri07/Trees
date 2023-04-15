#include<queue>
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int ans=0;
        while(!q.empty()){
            int size=q.size();
            int first,last;
            int mmin= q.front().second;
            for(int i=0;i<size;i++){
                TreeNode* Node = q.front().first;
                long cur_id = q.front().second-mmin;
               

                if(i==0){
                    first = q.front().second;
                    
                  
                }if(i==size-1){

                    last = q.front().second;
                 
                    
                } q.pop();
                if(Node->left){
                    q.push({Node->left,2*cur_id+1});
                }
                if(Node->right){
                    q.push({Node->right,2*cur_id+2});
                }  
            }
             ans = max(ans,(last-first+1));
            
            
        }
        return ans;
    }
};
