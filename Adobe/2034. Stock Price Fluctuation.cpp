class StockPrice {
public:
    map<int,int>mp;
    multiset<int>mt;
    void update(int timestamp, int price) {
        if(mp.find(timestamp)!=mp.end())
        mt.erase(mt.find(mp[timestamp]));
        mp[timestamp]=price;
        mt.insert(price);
    }
    
    int current() {
        return mp.rbegin()->second;
    }
    
    int maximum() {
        return *mt.rbegin();
    }
    
    int minimum() {
        return *mt.begin();
    }
};
