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
    int calPoints(vector<string> &operations)
    {
        stack<int> st;
        int n = operations.size();
        int i = 0;
        while (n--)
        {
            string x = operations[i];
            if (x == "+")
            {
                int a = st.top();
                st.pop();
                int y = st.top();
                st.push(a);
                st.push(a + y);
                i++;
            }
            else if (x == "D")
            {
                st.push(2 * (st.top()));
                i++;
            }
            else if (x == "C")
            {
                st.pop();
                i++;
            }
            else
            {
                st.push(stoi(x));
                i++;
            }
        }
        int m = st.size();
        int sum = 0;
        while (m--)
        {
            sum += st.top();
            st.pop();
        }
        return sum;
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
    vector<string> ops = {"1", "2", "+", "C", "5", "D"};
    int res = sol.calPoints(ops);
    cout << res;

    return 0;
}