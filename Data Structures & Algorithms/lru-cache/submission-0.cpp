class LRUCache {
public:
    
    class Node {
    public:
        int key;
        int value;
        Node* next;
        Node* prev;

        Node(int _key, int _value) {
            key = _key;
            value = _value;
            next = nullptr;
            prev = nullptr;
        }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    int cap;
    unordered_map<int, Node*> mp;

    LRUCache(int capacity) {
        cap = capacity;

        head->next = tail;
        tail->prev = head;
    }

    void deletenode(Node* node) {
        Node* nodeprev = node->prev;
        Node* nodenext = node->next;

        nodeprev->next = nodenext;
        nodenext->prev = nodeprev;
    }

    void addafter(Node* node) {
        Node* temp = head->next;

        head->next = node;
        node->next = temp;

        temp->prev = node;
        node->prev = head;
    }

    int get(int key) {

        if (mp.find(key) != mp.end()) {

            Node* ansnode = mp[key];
            int ans = ansnode->value;

            // Move to front
            deletenode(ansnode);
            addafter(ansnode);

            return ans;
        }

        return -1;
    }
    
    void put(int key, int value) {

        // If key already exists
        if (mp.find(key) != mp.end()) {

            Node* ansnode = mp[key];

            deletenode(ansnode);
            mp.erase(key);

            delete ansnode;
        }

        // If capacity is full
        if (mp.size() == cap) {

            Node* lru = tail->prev;

            mp.erase(lru->key);
            deletenode(lru);

            delete lru;
        }

        // Insert new node
        Node* ansnode = new Node(key, value);

        addafter(ansnode);
        mp[key] = ansnode;
    }
};