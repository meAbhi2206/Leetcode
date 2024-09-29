class AllOne {
public:
    unordered_map<string,int>count;
    set<pair<int,string>>st;
    AllOne() {
    }
    
    void inc(string key) {
         int n=count[key];
         count[key]++;
         st.erase({n,key});
         st.insert({n+1,key});
    }
    
    void dec(string key) {
         int n=count[key];
         count[key]--;
         st.erase({n,key});
         if(count[key]>0) st.insert({n-1,key});
         else count.erase(key);
    }
    
    string getMaxKey() {
        return !st.empty()?st.rbegin()->second : "";
    }
    
    string getMinKey() {
        return !st.empty()? st.begin()->second:"";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */