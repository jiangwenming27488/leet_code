class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        set<int> m_set;
        for(auto& element:A){
            if(m_set.find(element)!=m_set.end()){
                return element;
            }
            m_set.insert(element);
        }
        return 0;
    }
};
