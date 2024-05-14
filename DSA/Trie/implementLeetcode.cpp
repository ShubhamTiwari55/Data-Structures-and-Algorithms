// Leetcode ques no. 208 --> Implement trie (prefix tree)

class Node{
    public:
    char data;
    bool terminal;
    unordered_map<char, Node*> children;
    Node(char data){
        this->data = data;
        this->terminal = false;
    }
    void makeTerminal(){
        this->terminal = true;
    }
    bool isTerminal(){
        return this->terminal==true;
    }
};
class Trie {
public:
Node* root;
    Trie() {
        root = new Node('\0');
    }
    void insert(string word) {
        Node* curr = root;
        for(int i=0;i<word.length();i++){
            char ch = word[i];  //current ch to be checked
            if(curr->children.count(ch)){
                curr = curr->children[ch];
            }else{
                Node* child = new Node(ch);
                curr->children[ch] = child;
                curr = child;
            }
        }
        curr->makeTerminal();
    }
    
    bool search(string word) {
        Node* curr = root;
        for(int i=0;i<word.size();i++){
            char ch = word[i];
            if(curr->children.count(ch)) curr = curr->children[ch];
            else return false;
        }
        return curr->isTerminal();
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for(int i=0;i<prefix.size();i++){
            char ch = prefix[i];
            if(curr->children.count(ch)) curr = curr->children[ch];
            else return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */