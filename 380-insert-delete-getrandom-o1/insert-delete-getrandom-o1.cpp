class RandomizedSet {
public:

    unordered_map<int,int>M;
    vector<int>V;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        
        if(M.find(val) != M.end())
            return false;
        V.push_back(val);    
        M[val] = V.size()-1;
        
        return true;
    }
    
    bool remove(int val) {
        if(M.find(val) == M.end())
            return false;
       auto it = M.find(val);
       V[it->second] = V.back();
       V.pop_back();
       M[V[it->second]] = it->second;
       M.erase(val);
        return true;
    }
    
    int getRandom() {
        
        return V[rand()%V.size()];
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */