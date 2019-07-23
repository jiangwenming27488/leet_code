class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    /** Push element x to the back of queue. */
    void push(int x) {
        _list.emplace_back(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int element=peek();
        _list.pop_front();
        return element;
    }
    
    /** Get the front element. */
    int peek() {
        return *_list.begin();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return _list.size()==0;
    }
private:
    list<int> _list;
};
