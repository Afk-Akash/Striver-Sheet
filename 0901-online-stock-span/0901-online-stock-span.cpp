class StockSpanner {
    stack<pair<int,int>> st;
    int ind;
public:
    StockSpanner() {
        while(st.size())st.pop();
        ind = 0;
    }
    
    int next(int price) {
        while(st.size() and st.top().first <= price){
            st.pop();
        }
        
        int ans = st.size() ? ind - st.top().second :ind + 1;

        st.push({price,ind});
        // cout<<price<<" "<<ind<<endl;
        ind++;
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */