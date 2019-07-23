class LRUCache {
public:
    LRUCache(int capacity):m_capacity(capacity) {
    }
    int get(int key) {
        map_pos=m_map.find(key);
        int res=-1;
        if(map_pos!=m_map.end()){
            res=map_pos->second->second;
            m_list.erase(map_pos->second);
            m_list.emplace_front(make_pair(key,res));
            m_map[key]=m_list.begin();
        }
        return res;
    }
    void put(int key, int value) {
        map_pos=m_map.find(key);
        if(map_pos!=m_map.end()){
        	m_list.erase(map_pos->second);
        	m_list.emplace_front(make_pair(key,value));
        	m_map[key]=m_list.begin();
		}else{
			if(m_capacity<=m_list.size()){
				list<pair<int,int> >::iterator pos=m_list.end();
				--pos;
				m_map.erase(pos->first);
				m_list.erase(pos); 
			}
			m_list.emplace_front(make_pair(key,value));
			m_map.insert(make_pair(key,m_list.begin())); 
		}
    }
private:
    list<pair<int,int>> m_list;
    map<int,list<pair<int,int>>::iterator> m_map;
    int m_capacity;
    map<int,list<pair<int,int>>::iterator>::iterator map_pos;
};
