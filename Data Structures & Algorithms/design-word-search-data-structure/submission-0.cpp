class Node{
public:
    Node *links[26] = {nullptr};
    bool flag = false;

    bool containskey(char ch){
        return links[ch - 'a'] != nullptr;
    }

    void put(char ch, Node *node){
        links[ch - 'a'] = node;
    }

    Node* get(char ch){
        return links[ch - 'a'];
    }

    void setend(){
        flag = true;
    }

    bool isend(){
        return flag;
    }

    ~Node(){
        for(int i = 0; i < 26; i++){
            if(links[i] != nullptr){
                delete links[i];
                links[i] = nullptr;
            }
        }
    }
};

class WordDictionary {
    Node *root;

    bool dfs(Node *node, string &word, int index){
        if(index == word.size())
            return node->isend();

        char ch = word[index];

        if(ch == '.'){
            for(int i = 0; i < 26; i++){
                if(node->links[i] != nullptr){
                    if(dfs(node->links[i], word, index + 1))
                        return true;
                }
            }
            return false;
        }

        if(!node->containskey(ch))
            return false;

        return dfs(node->get(ch), word, index + 1);
    }

public:
    WordDictionary() {
        root = new Node();
    }

    ~WordDictionary(){
        delete root;
    }

    void addWord(string word) {
        Node *node = root;

        for(char ch : word){
            if(!node->containskey(ch)){
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }

        node->setend();
    }

    bool search(string word) {
        return dfs(root, word, 0);
    }
};