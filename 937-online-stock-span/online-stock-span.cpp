class StockSpanner {
    vector<int> stock;
    stack<int> s;

public:
    StockSpanner() {

    }

    int next(int price) {

        stock.push_back(price);

        int i = stock.size() - 1;

        while(!s.empty() && stock[i] >= stock[s.top()]) {
            s.pop();
        }

        int span;

        if(s.empty()) {
            span = i + 1;
        }
        else {
            span = i - s.top();
        }

        s.push(i);

        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */