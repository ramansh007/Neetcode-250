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
    vector<string> encode(vector<string> &strs)
    {

        string s;
        int n = strs.size();
        for (int i = 0; i < n; i++)
        {
            int l = strs[i].size();
            s += to_string(l);
            s += "#";
            s += strs[i];
        }

        vector<string> res = {};
        int i = 0;
        while (i < s.size())
        {
            int j = i;
            while (s[j] != '#')
            {
                j++;
            }
            int len = stoi(s.substr(i, j - i));
            i = j + 1;
            string sub = s.substr(i, len);
            res.push_back(sub);
            i = i + len;
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
    vector<string> strs = {"a", "ff"};
    vector<string> res = sol.encode(strs);
    cout << res;

    return 0;
}