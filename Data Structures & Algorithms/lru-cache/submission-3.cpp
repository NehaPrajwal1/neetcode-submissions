class Node {
public:
    int key;
    int value;
    Node* next;
    Node* prev;
    Node(int k, int v): key(k),value(v),next(nullptr),prev(nullptr){}
};



class LRUCache {
private:
    int cap;
    unordered_map<int,Node*> cache;
    Node* left;
    Node* right;
    void remove(Node* n)
    {
        Node* pv=n->prev;
        Node* nxt=n->next;
        pv->next=nxt;
        nxt->prev=pv;
    }
    void insert(Node* n)
    {
        Node* pv=right->prev;
        pv->next=n;
        n->prev=pv;
        n->next=right;
        right->prev=n;
    }

    public:
    LRUCache(int capacity) {
        cap=capacity;
        cache.clear();
        left=new Node(0,0);
        right=new Node(0,0);
        left->next=right;
        right->prev=left;
        
    }
    
    int get(int key) {
        if(cache.find(key)!=cache.end())
        {
            Node* n=cache[key];
            remove(n);
            insert(n);
            return n->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key)!=cache.end())
        {
            remove(cache[key]);
        }
        Node* n=new Node(key,value);
        cache[key]=n;
        insert(n);
        if(cache.size()>cap){
            Node* lru=left->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }      
    }
};
