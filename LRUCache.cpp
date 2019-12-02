#include<list>
#include<unordered_map>
#include<iterator>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
        mCapacity = capacity;
    }
    
    int get(int key) {
        auto iter = mMap.find(key);
        if (iter == mMap.end())
            return -1;
        pair<int, int> kv = *mMap[key];
        mCache.erase(mMap[key]);
        mCache.push_front(kv);
        mMap[key] = mCache.begin();
        return kv.second;
    }
    
    void put(int key, int value) {
        auto iter = mMap.find(key);
        if (iter == mMap.end())
        {
            if (mCache.size() == mCapacity)
            {
                auto cacheEnd = mCache.back();
                int keyEnd = cacheEnd.first;
                mMap.erase(keyEnd);
                mCache.pop_back();
            }
            mCache.push_front(make_pair(key, value));
            mMap[key] = mCache.begin();
        }
        else
        {
            mCache.erase(mMap[key]);
            mCache.push_front(make_pair(key, value));
            mMap[key] = mCache.begin();
        }
        
    }

private:
    int mCapacity;
    list<pair<int, int>> mCache;
    unordered_map<int, list<pair<int, int>>::iterator> mMap;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */