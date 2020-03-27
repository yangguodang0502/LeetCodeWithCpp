#include <list>
#include <vector>
#include <algorithm>

using namespace std;

class Bucket {
public:
    void add(int key)
    {
        if (contains(key))
            return;
        m_elements.push_front(key);
    }

    void remove(int key)
    {
        if (!contains(key))
            return;
        m_elements.remove(key);
    }

    bool contains(int key)
    {
        auto iter = find(m_elements.begin(), m_elements.end(), key);
        return iter != m_elements.end();
    }
private:
    list<int> m_elements;
};

class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        mSize = 769;
        mBuckets.assign(mSize, Bucket());
    }

    int hash(int key) {
        return key % mSize;
    }
    
    void add(int key) {
        int index = hash(key);
        mBuckets[index].add(key);
    }
    
    void remove(int key) {
        int index = hash(key);
        mBuckets[index].remove(key);
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int index = hash(key);
        return mBuckets[index].contains(key);
    }
private:
    vector<Bucket> mBuckets;
    int mSize;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */