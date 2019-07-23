class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) :value(k){
    }
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }
        _list.emplace_back(value);
        return true;
    }
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(isEmpty()) return false;
        _list.pop_front();
        return true;
    }
    /** Get the front item from the queue. */
    int Front() {
        if(isEmpty()) return -1;
        return *_list.begin();
    }
    /** Get the last item from the queue. */
    int Rear() {
        if(isEmpty()) return -1;
        return *_list.rbegin();
    }
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return _list.empty();
    }
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return _list.size()==value;
    }
private:
    deque<int> _list;
    int value;
};
