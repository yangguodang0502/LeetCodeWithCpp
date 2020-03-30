# 设计哈希映射
## 题目
Design a HashMap without using any built-in hash table libraries.

To be specific, your design should include these functions:
?put(key, value) : Insert a (key, value) pair into the HashMap. If the value already exists in the HashMap, update the value.
?get(key): Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
?remove(key) : Remove the mapping for the value key if this map contains the mapping for the key.


Example:
MyHashMap hashMap = new MyHashMap();
hashMap.put(1, 1);          
hashMap.put(2, 2);         
hashMap.get(1);            // returns 1
hashMap.get(3);            // returns -1 (not found)
hashMap.put(2, 1);          // update the existing value
hashMap.get(2);            // returns 1 
hashMap.remove(2);          // remove the mapping for 2
hashMap.get(2);            // returns -1 (not found) 



Note:
?All keys and values will be in the range of [0, 1000000].
?The number of operations will be in the range of [1, 10000].
?Please do not use the built-in HashMap library.

## 题解
### 算法分析
1. 定义桶类使用链表存储pair<key, value>元素，添加添加删除和查找接口
2. 定义桶数组和数组大小，初始化数组大小为一个大的质数，并创建该长度的数组用于存储桶
3. 定义哈希函数使用模运算计算桶序号
4. 调用桶序号对应的桶的接口实现添加删除和查找
### 复杂度分析
+ 时间复杂度：O(n/m)，n表示元素数量，m表示桶数量
+ 空间复杂度：O(m+k)，k表示当前元素数量
### 源码
```C++ []
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