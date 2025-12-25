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
    bool isAnagram(string s, string t)
    {

        int len1 = s.size();
        int len2 = t.size();

        if (len1 != len2)
            return false;

        map<char, int> map1;

        for (int i = 0; i < len1; i++)
        {
            map1[s[i]]++;
            map1[t[i]]--;
        }

        for (auto it : map1)
        {
            if (it.second != 0)
                return false;
        }

        return true;
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

    string s = "racecar";
    string t = "carrace";

    bool res = sol.isAnagram(s, t);

    cout << res << endl;

    string a = "bbcc";
    string b = "ccbc";

    bool res1 = sol.isAnagram(a, b);

    cout << res1 << endl;

    return 0;
}