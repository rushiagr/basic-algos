// borrowed from interviewbit

class LRUCache {
    private:
        typedef list<int> LI; // doubly linked list
        typedef pair<int, LI::iterator> PII;
        typedef unordered_map<int, PII> HIPII;

        void touch(HIPII::iterator it) {
            int key = it->first;
            used.erase(it->second.second);
            used.push_front(key);
            it->second.second = used.begin();
        }

        HIPII cache;
        LI used;
        int _capacity;

    public:
        LRUCache(int capacity) : _capacity(capacity) {
            cache.clear();
            used.clear();
        }

        int get(int key) {
            HIPII::iterator it = cache.find(key);
            if (it == cache.end()) return -1;
            touch(it);
            return it->second.first;
        }

        void set(int key, int value) {
            HIPII::iterator it = cache.find(key);
            if (it != cache.end()) touch(it);
            else {
                if (cache.size() == _capacity) {
                    cache.erase(used.back());
                    used.pop_back();
                }
                used.push_front(key);
            }
            cache[key] = make_pair(value, used.begin());
        }

};
