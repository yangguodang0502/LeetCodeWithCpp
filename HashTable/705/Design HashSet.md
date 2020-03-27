# ��ƹ�ϣ����
## ��Ŀ
Design a HashSet without using any built-in hash table libraries.

To be specific, your design should include these functions:

add(value): Insert a value into the HashSet. 
contains(value) : Return whether the value exists in the HashSet or not.
remove(value): Remove a value in the HashSet. If the value does not exist in the HashSet, do nothing.

Example:

MyHashSet hashSet = new MyHashSet();
hashSet.add(1);         
hashSet.add(2);         
hashSet.contains(1);    // returns true
hashSet.contains(3);    // returns false (not found)
hashSet.add(2);          
hashSet.contains(2);    // returns true
hashSet.remove(2);          
hashSet.contains(2);    // returns false (already removed)

Note:

All values will be in the range of [0, 1000000].
The number of operations will be in the range of [1, 10000].
Please do not use the built-in HashSet library.

## ���
### �㷨����
1. ����Ͱ��ʹ������洢Ԫ�أ�������ɾ���Ͳ��ҽӿ�
2. ����Ͱ����������С����ʼ�������СΪһ������������������ó��ȵ��������ڴ洢Ͱ
3. �����ϣ����ʹ��ģ�������Ͱ���
4. ����Ͱ��Ŷ�Ӧ��Ͱ�Ľӿ�ʵ�����ɾ���Ͳ���
### ���Ӷȷ���
+ ʱ�临�Ӷȣ�O(n/m)��n��ʾԪ��������m��ʾͰ����
+ �ռ临�Ӷȣ�O(m+k)��k��ʾ��ǰԪ������
### Դ��
```C++ []
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