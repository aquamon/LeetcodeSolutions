struct Trie{
        bool isEnd;
        Trie* child[26];
        Trie(){
            isEnd = false;
            for(int i=0;i<26;i++)
                child[i] = NULL;
        }

        bool containsChar(char ch){
            return (child[ch-'a'] != NULL);
        }

        void put(char ch,Trie* node){
            child[ch-'a'] = node;
        }

        Trie* get(char ch){
            return child[ch-'a'];
        }
    };
class Solution {
public:

    int countChild(Trie* node, int *index){
        int count = 0;
        for(int i=0;i<26;i++){
            if(node->child[i] != NULL){
                count++;
                *index = i;
            }
        }

        return count;
    }
    string traverse(Trie* root){
        int index=0;
        string prefix;

        Trie* temp = root;

        while(countChild(temp,&index) == 1 and temp->isEnd == false){
            prefix.push_back('a'+index);
            temp = temp->child[index];
        }

        return prefix;
    }
    string longestCommonPrefix(vector<string>& strs) {
        
        Trie* root = new Trie();

        for(string S : strs){
            if(S=="")
                return "";
            
            Trie* temp = root;
            for(int i=0;i<S.size();i++){
                if(!temp->containsChar(S[i])){
                    temp->put(S[i],new Trie());
                }
                temp = temp->get(S[i]);
            }
            temp->isEnd = true;
        }

        string prefix = traverse(root);

        return prefix;
    }
};