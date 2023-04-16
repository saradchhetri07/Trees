class Codec {
public:

    // Encodes a tree to a single string.
 
    
    string serialize(TreeNode* root) {
        if(!root){
            return "";
        }
        string serialized="";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            
            TreeNode* curNode = q.front();
            q.pop();
            if(curNode==NULL){
                serialized.append("#,");
            }else{
                serialized.append(to_string(curNode->val)+",");
            }
            if(curNode!=NULL){
                q.push(curNode->left);
                q.push(curNode->right);
            }

            // int size = q.size();
            // for(int i=0;i<size;i++){
            //     TreeNode* front = q.front();
            //     q.pop();
                
            //     if(!front->left){
            //          serialized.append("#,");
            //     }
            //     if(front->left){
            //         q.push(front->left);
            //         serialized += to_string(front->left->val) + ',';
            //     }
            //     if(!front->right){
            //          serialized.append("#,");
            //     }
            //     if(front->right){
            //         q.push(front->right);
            //         serialized += to_string(front->right->val) + ',';
            //     }
               
            // }
             
        }
        
        return serialized;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0){
            return NULL;
        }
       stringstream serialized(data);
       string str;
       getline(serialized,str,',');
       TreeNode* root = new TreeNode(stoi(str));
       queue<TreeNode*> q;
       q.push(root);

       while(!q.empty()){
           TreeNode* front = q.front();
            q.pop();

            getline(serialized,str,',');
            if(str == "#"){
                front->left = NULL;
            }else{
                TreeNode* node = new TreeNode(stoi(str));
                front->left = node;
                q.push(front->left);
            }

            getline(serialized,str,',');
            if(str=="#"){
                front->right = NULL;
            }else{
                TreeNode* node = new TreeNode(stoi(str));
                front->right = node;
                 q.push(front->right);
            }
       }
        return root;
    }
};
