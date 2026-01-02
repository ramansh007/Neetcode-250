#include <bits/stdc++.h>
using namespace std;

// =========================
// 1. TYPEDEFS
// =========================
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;

// =========================
// 2. DEBUGGING MAGIC
// =========================
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p)
{
    return os << "(" << p.first << ", " << p.second << ")";
}

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    os << "[";
    for (size_t i = 0; i < v.size(); ++i)
    {
        os << v[i] << (i < v.size() - 1 ? ", " : "");
    }
    return os << "]";
}

// =========================
// 3. SOLUTION CLASS
// =========================
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> stack;
        int res = 0;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] == "+")
            {
                int top = stack.top();
                stack.pop();
                int top2 = stack.top();
                stack.pop();
                stack.push((top + top2));
            }

            else if (tokens[i] == "-")
            {
                int top = stack.top();
                stack.pop();
                int top2 = stack.top();
                stack.pop();
                stack.push((top2 - top));
            }

            else if (tokens[i] == "*")
            {
                int top = stack.top();
                stack.pop();
                int top2 = stack.top();
                stack.pop();
                stack.push((top2 * top));
            }

            else if (tokens[i] == "/")
            {
                int top = stack.top();
                stack.pop();
                int top2 = stack.top();
                stack.pop();
                stack.push((top2 / top));
            }
            else
            {
                stack.push(stoi(tokens[i]));
            }
        }
        res = stack.top();
        return res;
    }
};

// =========================
// 4. MAIN FUNCTION
// =========================
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    // --- TEST CASE ---
    vector<string> tokens = {"1", "2", "+", "3", "*", "4", "-"};
    int res = sol.evalRPN(tokens);
    cout << res;

    return 0;
}