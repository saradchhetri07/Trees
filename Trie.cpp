struct Node{
    Node *links[26];
    bool flag=false;

    bool containsKey(char ch){
    return (links[ch-'a']!=NULL);
    }
    void putWord(char ch,Node* node){
        links[ch-'a']=node;
    }
    Node* getWord(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        flag = true;
    }
    bool getEnd(){
        return flag;
    }

};
class Trie {
private: Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                node->putWord(word[i],new Node());
            }
            //moves to reference trie
            node = node->getWord(word[i]);
        }
       node->setEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node = node->getWord(word[i]);
        }

        return node->getEnd();

    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i=0;i<prefix.size();i++){
            if(!node->containsKey(prefix[i])){
                return false;
            }
            node = node->getWord(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
