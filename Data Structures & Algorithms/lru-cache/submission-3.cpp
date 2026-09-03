class LRUCache {
    struct Node {
        int key;
        int val;
        Node* next = nullptr;
        Node* prev = nullptr;
        Node(int _key, int _val) {
            key = _key;
            val = _val;
        }
    };

    unordered_map<int, Node*> cache_map;
    Node* head = nullptr;
    Node* tail = nullptr;
    int cap;

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addToTail(Node* node) {
        tail->prev->next = node;
        node->prev = tail->prev;
        tail->prev = node;
        node->next = tail;
    }
public:
    LRUCache(int capacity) {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        cap = capacity;
        cache_map.clear();
    }
    
    int get(int key) {
        if(cache_map.contains(key)) {
            Node* node = cache_map[key];

            remove(node);
            addToTail(node);

            return node->val;
        }
        else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        
        if(cache_map.contains(key)) {
            Node* node = cache_map[key];

            remove(node);
            addToTail(node);

            node->val = value;
        }
        else {

            //Check for cachemap sizing
            if(cache_map.size() >= cap) {
                int headKey = head->next->key;
                remove(head->next);
                cache_map.erase(headKey);
            }

            //Add new node to tail
            Node* newNode = new Node(key, value);
            addToTail(newNode);
            cache_map[key] = newNode;
        }
    }
};
