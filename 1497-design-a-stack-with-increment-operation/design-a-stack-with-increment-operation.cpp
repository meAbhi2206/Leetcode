class CustomStack {
public:
vector<int>st;
int top,size;
    CustomStack(int maxSize) {
        st.resize(maxSize);
        size=maxSize;
        top=-1;
    }
    
    void push(int x) {
        if(top<size-1){
            top++;
            st[top]=x;
        }
    }
    
    int pop() {
        if(top!=-1){
            return st[top--];
        }
        return -1;
    }
    
    void increment(int k, int val) {
       for (int i=0;i<min(top+1,k);i++) st[i]+=val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */