class StockSpanner {
public:
stack<pair<int,int>>s;
int i=0;
int ans;
    StockSpanner() { 
    }
    
    int next(int price) {
        if(s.size()==0){
            ans=-1;
        }
        else{
            while(!s.empty() && s.top().first<=price){
                s.pop();
            }
            if(s.size()==0) ans=-1;
            else ans=s.top().second;
        }
        s.push({price,i});
        int span=i-ans;
        i++;
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */