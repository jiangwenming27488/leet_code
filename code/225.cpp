class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        _list.emplace_back(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int element=top();
        _list.pop_back();
        return element;
    }
    
    /** Get the top element. */
    int top() {
        return *_list.rbegin();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return _list.size()==0;
    }
private:
    list<int> _list;
};
