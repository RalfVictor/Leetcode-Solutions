class Node{
    public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int key, int val) : key(key), val(val), prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    void remove(Node* node){
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    void insert(Node* node){
        Node* prev = first->prev;
        Node* next = first;
        prev->next = node;
        next->prev = node;
        node->next = first;
        node->prev = prev;
    }

    int cap;
    unordered_map<int,Node*> cache;
    Node* old;
    Node* first;
    LRUCache(int capacity): cap(capacity) {
        old = new Node(0,0);
        first = new Node(0,0);
        old->next = first;
        first->prev = old;
    }
    
    int get(int key) {
        if(cache.find(key)!=cache.end()){
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->val;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key)!=cache.end()){
            remove(cache[key]);
        }
        Node* newNode = new Node(key,value);
        cache[key] = newNode;
        insert(newNode);
        if(cache.size()>cap){
            Node* lru = old->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */