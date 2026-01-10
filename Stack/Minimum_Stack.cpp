class MinStack
{
private:
    stack<int> st;
    stack<int> min;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        st.push(val);
        val = std::min(val, (min.empty() ? val : min.top()));
        min.push(val);
    }

    void pop()
    {
        st.pop();
        min.pop();
    }

    int top()
    {
        return st.top();
    }

    int getMin()
    {

        return min.top();
    }
};
