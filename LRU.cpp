class LFUCache {
public:
   
    LFUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            int val=container[mp[key]][key];
            int pos=mp[key];
            mp[key]++;
            container[pos].erase(key);
            pos++;
            container[pos][key]=val;
            return val;
        }
        else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(mp.count(key)==0){
        if(mp.size()==cap){
            auto it = container.begin();
            auto it2=it->second.begin();
            mp.erase(it2->first);
            it->second.erase(it2->first);
            mp[key]=1;
            container[1][key]=value;

        } 
        else{
            mp[key]=1;
            container[1][key]=value;
        }
        
        }
        else{
           int pos=mp[key];
           mp[key]++;
           container[pos].erase(key);
           container[pos+1][key]=value; 
        }
    }
private:
    unordered_map<int,int> mp;
    map<int,unordered_map<int,int>> container;
    int cap=0;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */