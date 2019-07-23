class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        auto pos=find(key);
        if(pos==vec.end()){
            vec.emplace_back(std::make_pair(key,value));
        }else{
            pos->second=value;
        }
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        auto pos=find(key);
        if(pos==vec.end()) return -1;
        return pos->second;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        auto pos=find(key);
        if(pos!=vec.end())  vec.erase(pos);
    }
    vector<pair<int,int>>::iterator find(int key){
        return find_if(vec.begin(),vec.end(),[&](const pair<int,int>& pair){
            return pair.first==key;
        });
    }
    vector<pair<int,int>> vec;
};
