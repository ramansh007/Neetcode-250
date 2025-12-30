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
// class Solution
// {
// public:
//     bool isValid(string s)
//     {
//         stack<char> st;
//         for (int i = 0; i < s.size(); i++)
//         {
//             if (s[i] == '(' || s[i] == '{' || s[i] == '[')
//                 st.push(s[i]);
//             else
//             {
//                 if (s[i] == ')')
//                 {
//                     if (st.empty())
//                         st.push(s[i]);
//                     else
//                     {
//                         if (st.top() != '(')
//                             st.push(s[i]);
//                         else
//                             st.pop();
//                     }
//                 }

//                 if (s[i] == '}')
//                 {
//                     if (st.empty())
//                         st.push(s[i]);
//                     else
//                     {
//                         if (st.top() != '{')
//                             st.push(s[i]);
//                         else
//                             st.pop();
//                     }
//                 }

//                 if (s[i] == ']')
//                 {
//                     if (st.empty())
//                         st.push(s[i]);
//                     else
//                     {
//                         if (st.top() != '[')
//                             st.push(s[i]);
//                         else
//                             st.pop();
//                     }
//                 }
//             }
//         }

//         return (st.empty());
//     }
// };

// ---------------------------------- Optimized Solution

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);
            else
            {
                if (st.empty())
                    return false;
                char top = st.top();
                if (s[i] == ')' && top == '(' || s[i] == '}' && top == '{' || s[i] == ']' && top == '[')
                    st.pop();
                else
                {
                    return false;
                }
            }
        }

        return (st.empty());
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

    string s = "[]";
    bool res = sol.isValid(s);
    cout << res;
    return 0;
}