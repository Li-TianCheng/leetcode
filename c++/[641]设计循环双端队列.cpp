//设计实现双端队列。 
//你的实现需要支持以下操作： 
//
// 
// MyCircularDeque(k)：构造函数,双端队列的大小为k。 
// insertFront()：将一个元素添加到双端队列头部。 如果操作成功返回 true。 
// insertLast()：将一个元素添加到双端队列尾部。如果操作成功返回 true。 
// deleteFront()：从双端队列头部删除一个元素。 如果操作成功返回 true。 
// deleteLast()：从双端队列尾部删除一个元素。如果操作成功返回 true。 
// getFront()：从双端队列头部获得一个元素。如果双端队列为空，返回 -1。 
// getRear()：获得双端队列的最后一个元素。 如果双端队列为空，返回 -1。 
// isEmpty()：检查双端队列是否为空。 
// isFull()：检查双端队列是否满了。 
// 
//
// 示例： 
//
// MyCircularDeque circularDeque = new MycircularDeque(3); // 设置容量大小为3
//circularDeque.insertLast(1);			        // 返回 true
//circularDeque.insertLast(2);			        // 返回 true
//circularDeque.insertFront(3);			        // 返回 true
//circularDeque.insertFront(4);			        // 已经满了，返回 false
//circularDeque.getRear();  				// 返回 2
//circularDeque.isFull();				        // 返回 true
//circularDeque.deleteLast();			        // 返回 true
//circularDeque.insertFront(4);			        // 返回 true
//circularDeque.getFront();				// 返回 4
//  
//
// 
//
// 提示： 
//
// 
// 所有值的范围为 [1, 1000] 
// 操作次数的范围为 [1, 1000] 
// 请不要使用内置的双端队列库。 
// 
// Related Topics 设计 队列 
// 👍 75 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class MyCircularDeque {
private:
    struct Node {
        Node* prev = nullptr;
        Node* next = nullptr;
        int value = 0;
    };
    Node* head = nullptr;
    Node* tail = nullptr;
    int maxSize = 0;
    int size = 0;
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        maxSize = k;
        head = new Node;
        tail = new Node;
        head->next = tail;
        tail->prev = head;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (size >= maxSize){
            return false;
        }
        Node* temp = new Node;
        temp->value = value;
        temp->next = head->next;
        temp->prev = head;
        head->next->prev = temp;
        head->next = temp;
        size++;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (size >= maxSize){
            return false;
        }
        Node* temp = new Node;
        temp->value = value;
        temp->next = tail;
        temp->prev = tail->prev;
        tail->prev->next = temp;
        tail->prev = temp;
        size++;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (size <= 0){
            return false;
        }
        Node* temp = head->next;
        head->next = head->next->next;
        head->next->prev = head;
        size--;
        delete temp;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (size <= 0){
            return false;
        }
        Node* temp = tail->prev;
        tail->prev = tail->prev->prev;
        tail->prev->next = tail;
        size--;
        delete temp;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        return size > 0 ? head->next->value : -1;
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        return size > 0 ? tail->prev->value : -1;
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return size == 0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return size == maxSize;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
//leetcode submit region end(Prohibit modification and deletion)
