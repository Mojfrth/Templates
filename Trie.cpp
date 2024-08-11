struct Node{
  Node *l[26];
    bool f=0;
    
    bool ck(char ch){
        return l[ch-'a']!=NULL;
    }
    
    void put(char ch,Node *node){
        l[ch-'a']=node;
    }
    Node *get(char ch){
        return l[ch-'a'];
    }
    void se(){
        f=1;
    }
    bool ise(){
        return f;
    }
};


class Trie {
    private:
    Node *root;
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string w) {
        Node *node=root;
        for(int i=0;i<w.length();i++){
            if(!(node->ck(w[i]))){
                node->put(w[i],new Node());
            }
             node=node->get(w[i]);
        }
        node->se();
    }
    
    bool search(string w) {
        Node *node=root;
        for(int i=0;i<w.length();i++){
            if(!node->ck(w[i])){
                return false;
            }
            node=node->get(w[i]);
        }
        return node->ise();
    }
    
    bool startsWith(string w) {
        Node *node=root;
        for(int i=0;i<w.length();i++){
            if(!node->ck(w[i])){
                return false;
            }
            node=node->get(w[i]);
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
