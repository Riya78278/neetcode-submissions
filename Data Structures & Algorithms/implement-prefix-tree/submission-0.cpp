struct Node{
    Node* links[26]={nullptr};
    bool flag=false;

    //containskey
    bool containskey(char ch){
        return links[ch-'a'] != nullptr;
    }  

    //put
    void put(char ch, Node * node){
        links[ch-'a']=node;
    }

    //get
    Node* get(char ch){
        return links[ch-'a'];
    }
    //set end

    void setEnd() {
        flag = true;
    }
    //isend
    bool isend(){
        return flag;
    }

    ~Node(){
        for(int i=0;i<26;i++){
            if(links[i]!=nullptr){
                delete links[i];
                links[i]=nullptr;
            }
        }
    }

};
class PrefixTree {
private:
    Node*root;    
public:
    PrefixTree() {
        root=new Node(); 
    }

    ~PrefixTree(){
        delete root;
    }
    
    void insert(string word) {
        Node* node=root;
        for(char ch:word){
            if(!node->containskey(ch)){
                node->put(ch, new Node());
            }
            node=node->get(ch);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node=root;
        for(char ch:word){
            if(!node->containskey(ch)){
                return false;
            }
            node=node->get(ch);
        }
        return node->isend();
    }
    
    bool startsWith(string prefix) {
        Node* node=root;
        for(char ch: prefix){
            if(!node->containskey(ch)){
                return false;
            }
            node=node->get(ch);
        }
        return true;
    }
};
