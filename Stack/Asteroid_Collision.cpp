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
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        vi res = {};
        int n = asteroids.size();
        stack<int> st;
        for (int i = 0; i < n; i++)
        {

            int a = asteroids[i];

            while (!st.empty() && st.top() > 0 && a < 0)
            {
                int top = st.top();
                int diff = top + a;

                if (diff < 0)
                {
                    st.pop();
                }
                else if (diff > 0)
                {
                    a = 0;
                }
                else
                {

                    a = 0;
                    st.pop();
                }
            }

            if (a != 0)
            {
                st.push(a);
            }
        }

        while (!st.empty())
        {
            // cout << st.top() << " ";
            res.insert(res.begin(), st.top());
            st.pop();
        }

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
    vi asteroids = {-1, 4, -3};
    vi res = sol.asteroidCollision(asteroids);
    cout << res;
    return 0;
}