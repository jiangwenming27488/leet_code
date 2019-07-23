class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k):value(k){
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(isFull()) return false;
        _deque.emplace_front(value);
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(isFull()) return false;
        _deque.emplace_back(value);
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(isEmpty()) return false;
        _deque.pop_front();
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(isEmpty()) return false;
        _deque.pop_back();
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if(isEmpty()) return -1;
        return *_deque.begin();
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if(isEmpty()) return -1;
        return *_deque.rbegin();
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return _deque.empty();
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return _deque.size()==value;
    }
private:
    int value;
    deque<int> _deque;
};
