class MyStack
{
private:
    queue<int> q1;
    queue<int> q2;

public:
    MyStack()
    {
    }

    void push(int x)
    {
        q1.push(x);
    }

    int pop()
    {
        q2 = queue<int>();
        int return_element;
        while (!q1.empty())
        {
            if (q1.size() == 1)
            {
                return_element = q1.front();
                break;
            }
            int element = q1.front();
            q2.push(element);
            q1.pop();
        }

        q1 = q2;
        return return_element;
    }

    int top()
    {
        int top = q1.back();
        return top;
    }

    bool empty()
    {

        if (!q1.empty())
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */