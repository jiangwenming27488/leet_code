class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        _list.emplace_back(x);
    }
    
    void pop() {
        _list.pop_back();
    }
    
    int top() {
        return *_list.rbegin();
    }
    
    int getMin() {
        int element=top();
        for(auto& ele:_list){
            if(ele<element){
                element=ele;
            }
        }
        return element;
    }
private:
    list<int> _list;
};
