//实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。 
//
// 示例: 
//
// Trie trie = new Trie();
//
//trie.insert("apple");
//trie.search("apple");   // 返回 true
//trie.search("app");     // 返回 false
//trie.startsWith("app"); // 返回 true
//trie.insert("app");   
//trie.search("app");     // 返回 true 
//
// 说明: 
//
// 
// 你可以假设所有的输入都是由小写字母 a-z 构成的。 
// 保证所有输入均为非空字符串。 
// 
// Related Topics 设计 字典树 
// 👍 508 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
//class Trie {
//private:
//    struct Node {
//        unordered_map<char, Node*> children;
//    };
//    Node* root = nullptr;
//public:
//    /** Initialize your data structure here. */
//    Trie() {
//        this->root = new Node();
//    }
//
//    /** Inserts a word into the trie. */
//    void insert(string word) {
//        Node* curr = root;
//        for (auto& c : word){
//            if (curr->children.find(c) == curr->children.end()){
//                curr->children[c] = new Node();
//            }
//            curr = curr->children[c];
//        }
//        curr->children['0'] = new Node();
//    }
//
//    /** Returns if the word is in the trie. */
//    bool search(string word) {
//        Node* curr = root;
//        for (auto& c : word){
//            if (curr->children.find(c) == curr->children.end()){
//                return false;
//            }
//            curr = curr->children[c];
//        }
//        return curr->children.find('0') != curr->children.end();
//    }
//
//    /** Returns if there is any word in the trie that starts with the given prefix. */
//    bool startsWith(string prefix) {
//        Node* curr = root;
//        for (auto& c : prefix){
//            if (curr->children.find(c) == curr->children.end()){
//                return false;
//            }
//            curr = curr->children[c];
//        }
//        return true;
//    }
//
//    ~Trie(){
//        dfs(root);
//    }
//
//    void dfs(Node* node){
//        if (node == nullptr){
//            return;
//        }
//        for (auto& child : node->children){
//            dfs(child.second);
//        }
//        delete node;
//    }
//};

class Trie {
private:
    struct Node {
        Node* children[27];
    };
    Node* root = nullptr;
public:
    /** Initialize your data structure here. */
    Trie() {
        this->root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* curr = root;
        for (auto& c : word){
            c -= 'a';
            if (curr->children[c] == nullptr){
                curr->children[c] = new Node();
//                curr->children[c]->c = c;
            }
            curr = curr->children[c];
        }
        curr->children[26] = new Node();
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* curr = root;
        for (auto& c : word){
            c -= 'a';
            if (curr->children[c] == nullptr){
                return false;
            }
            curr = curr->children[c];
        }
        return curr->children[26] != nullptr;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* curr = root;
        for (auto& c : prefix){
            c -= 'a';
            if (curr->children[c] == nullptr){
                return false;
            }
            curr = curr->children[c];
        }
        return true;
    }

    ~Trie(){
        dfs(root);
    }

    void dfs(Node* node){
        if (node == nullptr){
            return;
        }
        for (auto& child : node->children){
            dfs(child);
        }
        delete node;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
//leetcode submit region end(Prohibit modification and deletion)
