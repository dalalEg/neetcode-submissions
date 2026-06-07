class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
    Node* leftRoot;
    Node* rightRoot;
    int cap;
    unordered_map<int, Node*> cache;
    void remove(int key){
        Node* curr=cache[key];
        curr->prev->next=curr->next;
        curr->next->prev=curr->prev;
    }
    void insert(int key){
         Node* curr=cache[key];
         Node* last=rightRoot->prev;
         last->next=curr;
         curr->prev=last;
         curr->next=rightRoot;
         rightRoot->prev=curr;
    }
public:
    LRUCache(int capacity) {
        cap = capacity;
        cache.clear();
        leftRoot = new Node(0, 0);
        rightRoot = new Node(0, 0);
        leftRoot->next = rightRoot;
        rightRoot->prev = leftRoot;
    }
    
    int get(int key) {
        if (cache.find(key)==cache.end())
            return -1;
        int val = cache[key]->val;
        remove(key);
        insert(key);
        return val;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            remove(key);
        }
        Node* newNode= new Node(key,value);
        cache[key]=newNode;
        insert(key);
        if(cache.size()>cap){
            Node* toDelete=leftRoot->next;
            remove(toDelete->key);
            cache.erase(toDelete->key);
            delete toDelete;
        }
      

    }
};
