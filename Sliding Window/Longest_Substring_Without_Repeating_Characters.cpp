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
    int lengthOfLongestSubstring(string s)
    {

        int n = s.size();
        if (n == 0)
            return 0;

        int maxlen = 1;
        int j = 0;
        int i = 0;
        unordered_set<char> set;
        while (j < n)
        {
            while (set.count(s[j]))
            {

                set.erase(s[i]);
                i++;
            }

            set.insert(s[j]);
            maxlen = max(maxlen, j - i + 1);
            j++;
        }

        return maxlen;
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
    string s = "dvdf";
    int res = sol.lengthOfLongestSubstring(s);
    cout << res;

    return 0;
}