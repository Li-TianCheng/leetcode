//运用你所掌握的数据结构，设计和实现一个 LRU (最近最少使用) 缓存机制 。 
//
// 
// 
// 实现 LRUCache 类： 
//
// 
// LRUCache(int capacity) 以正整数作为容量 capacity 初始化 LRU 缓存 
// int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。 
// void put(int key, int value) 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字-值」。当缓存容量达到上
//限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。 
// 
//
// 
// 
// 
//
// 进阶：你是否可以在 O(1) 时间复杂度内完成这两种操作？ 
//
// 
//
// 示例： 
//
// 
//输入
//["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
//[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
//输出
//[null, null, null, 1, null, -1, null, -1, 3, 4]
//
//解释
//LRUCache lRUCache = new LRUCache(2);
//lRUCache.put(1, 1); // 缓存是 {1=1}
//lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
//lRUCache.get(1);    // 返回 1
//lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
//lRUCache.get(2);    // 返回 -1 (未找到)
//lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
//lRUCache.get(1);    // 返回 -1 (未找到)
//lRUCache.get(3);    // 返回 3
//lRUCache.get(4);    // 返回 4
// 
//
// 
//
// 提示： 
//
// 
// 1 <= capacity <= 3000 
// 0 <= key <= 3000 
// 0 <= value <= 104 
// 最多调用 3 * 104 次 get 和 put 
// 
// Related Topics 设计 
// 👍 1013 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class LRUCache {
    class Node{
        private int key;
        private int value;
        private Node prev = null;
        private Node next = null;

        public Node(int key, int value){
            this.key = key;
            this.value = value;
        }

        public Node getPrev(){
            return prev;
        }

        public Node getNext(){
            return next;
        }

        public int getKey(){
            return key;
        }

        public int getValue(){
            return value;
        }

        public void setPrev(Node prev){
            this.prev = prev;
        }

        public void setNext(Node next){
            this.next = next;
        }

        public void setValue(int value){
            this.value = value;
        }
    }

    private HashMap<Integer, Node> cache = new HashMap<Integer, Node>();
    private int size;
    private int capacity;
    private Node head;
    private Node tail;

    public LRUCache(int capacity) {
        this.capacity = capacity;
        size = 0;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head.setNext(tail);
        tail.setPrev(head);
    }

    public int get(int key) {
        if (!cache.containsKey(key)) {
            return -1;
        }
        Node curr = cache.get(key);
        moveToFirst(curr);
        return curr.getValue();
    }

    public void put(int key, int value) {
        if (!cache.containsKey(key)) {
            Node curr = new Node(key, value);
            size++;
            cache.put(key, curr);
            head.getNext().setPrev(curr);
            curr.setNext(head.getNext());
            curr.setPrev(head);
            head.setNext(curr);
            if (size > capacity){
                removeLast();
                size--;
            }
        }else{
            Node curr = cache.get(key);
            curr.setValue(value);
            moveToFirst(curr);
        }
    }

    private void moveToFirst(Node curr){
        curr.getPrev().setNext(curr.getNext());
        curr.getNext().setPrev(curr.getPrev());
        head.getNext().setPrev(curr);
        curr.setNext(head.getNext());
        curr.setPrev(head);
        head.setNext(curr);
    }

    private void removeLast(){
        Node last = tail.getPrev();
        cache.remove(last.getKey());
        last.getPrev().setNext(tail);
        tail.setPrev(last.getPrev());
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
//leetcode submit region end(Prohibit modification and deletion)
