#include <list>
#include <vector>
#include <algorithm>

using namespace std;

class Bucket {
public:
    void put(int key, int value)
    {
        for (auto iter = mElements.begin(); iter != mElements.end(); ++iter)
        {
            if (iter->first == key)
            {
                iter->second = value;
                return;
            }
        }
        mElements.push_front(make_pair(key, value));
    }

    int get(int key)
    {
        for (auto iter = mElements.begin(); iter != mElements.end(); ++iter)
        {
            if (iter->first == key)
                return iter->second;
        }
        return -1;
    }

    void remove(int key)
    {
        for (auto iter = mElements.begin(); iter != mElements.end(); ++iter)
        {
            if (iter->first == key)
            {
                mElements.erase(iter);
                break;
            }
        }
    }
private:
    list<pair<int, int>> mElements;
};

class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        mSize = 769;
        mBuckets.assign(mSize, Bucket());
    }

    int hash(int key)
    {
        return key % mSize;
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int index = hash(key);
        mBuckets[index].put(key, value);
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int index = hash(key);
        return mBuckets[index].get(key);
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int index = hash(key);
        mBuckets[index].remove(key);
    }
private: 
    vector<Bucket> mBuckets;
    int mSize;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */