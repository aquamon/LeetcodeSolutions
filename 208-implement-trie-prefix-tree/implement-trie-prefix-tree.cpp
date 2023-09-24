  struct TrieNode{
        bool isEnd;
        TrieNode* child[26];


        TrieNode(){
            isEnd = false;
            for(int i=0;i<26;i++)
                child[i] = NULL;
        }

        bool containsChar(char ch)
        {
            return (child[ch-'a'] != NULL);
        }
        void put(char ch,TrieNode* node)
        {
            child[ch-'a'] = node;
        }
        TrieNode* get(char ch)
        {
            return child[ch-'a'];
        }
        void setEnd()
        {
            isEnd = true;
        }
        bool isTheEnd()
        {
            return isEnd;
        }

        
    };   
class Trie {
   
private : 
    TrieNode* root;

public:

    
   
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        
        TrieNode *temp = root;
        for(int i=0;i<word.length();i++)
        {
            if(!temp->containsChar(word[i]))
            {
                temp->put(word[i],new TrieNode());
            }
            temp = temp->get(word[i]);
           
        }
        temp->setEnd();      
    }
    
    bool search(string word) {
        
        TrieNode* temp = root;

        for(int i=0;i<word.length();i++)
        {
            if(!temp->containsChar(word[i]))
                return false;
            temp = temp->get(word[i]);
        }
        
        return temp->isTheEnd();
        
    }
    
    bool startsWith(string prefix) {
        
        TrieNode* temp = root;

        for(int i=0;i<prefix.length();i++)
        {
            if(!temp->containsChar(prefix[i]))
                return false;
            temp = temp->get(prefix[i]);
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