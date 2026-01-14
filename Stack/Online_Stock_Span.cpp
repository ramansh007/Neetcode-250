

class StockSpanner
{
    stack<pair<int, int>> st;
    int j = 0;

public:
    StockSpanner()
    {
    }

    int next(int price)
    {

        int len;
        while (!st.empty() && price >= st.top().first)
        {
            st.pop();
        }
        if (!st.empty())
        {
            len = j - st.top().second;
        }
        else
            len = j + 1;

        st.push({price, j});
        j++;
        return len;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */