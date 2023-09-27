struct Node{
    
    Node* links[2];
    int num;
    
    bool containsKey(char ch)
    {
        return (links[ch - '0'] != NULL);
    }
    
    void put(char ch, Node* node)
    {
        links[ch-'0'] = node;
    }
    
    Node* get(char ch)
    {
        return links[ch-'0'];
    }
};
class Solution {
public:
    string toBin(int N)
    {
        string res = "";
        
        while(N>0)
        {
            int rem = N%2;
            N /= 2;
            
            res += (rem+'0');
        }
        
        while(res.size()<32)
        {
            res += '0';
        }
        
        return string(res.rbegin(),res.rend());
    }
    
    void insert(Node* root,string S,int N)
    {
        Node* temp = root;
        
        for(int i=0;i<S.size();i++)
        {
            if(!temp->containsKey(S[i]))
            {
                temp->put(S[i],new Node());
            }
            temp = temp->get(S[i]);
        }
        temp->num = N;
    }
    
    int trav(Node* root, int N)
    {
        string resN = toBin(N);
        Node* temp = root;
        for(int i=0;i<resN.size();i++)
        {
            if(resN[i] == '0')
            {
                if(temp->containsKey('1'))
                {
                    temp = temp->get('1');
                }
                else
                {
                    temp = temp->get('0');
                }
            }
            else
            {
                if(temp->containsKey('0'))
                {
                    temp = temp->get('0');
                }
                else
                {
                    temp = temp->get('1');
                }
            }
        }
        return N^temp->num;
    }
    
    int findMaximumXOR(vector<int>& arr) {
         int ans = 0;
        
        Node* root = new Node();
        
        for(int i=0;i<arr.size();i++)
        {
            
            insert(root,toBin(arr[i]),arr[i]);
        }
        
        for(int i=0;i<arr.size();i++)
        {
            ans = max(ans,trav(root,arr[i]));
        }
        
        return ans;
    }
};