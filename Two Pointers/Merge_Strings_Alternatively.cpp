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
//     string mergeAlternately(string word1, string word2)
//     {
//         int l1 = word1.size();
//         int l2 = word2.size();
//         int i = 0, j = 0;
//         string res = "";
//         while (i < l1 && j < l2)
//         {
//             res += word1[i];
//             res += word2[j];

//             i++;
//             j++;
//         }

//         while (i < l1)
//         {
//             res += word1[i];
//             i++;
//         }

//         while (j < l2)
//         {
//             res += word2[j];
//             j++;
//         }

//         return res;
//     }
// };
// --------------------------------- More optimized Two pointer Solution
class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        int l1 = word1.size();
        int l2 = word2.size();
        int i = 0, j = 0;
        string res = "";

        while (i < l1 || j < l2)
        {
            if (i < l1)
                res += word1[i++];
            if (j < l2)
                res += word2[j++];
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
    string word1 = "abcdddd";
    string word2 = "xyz";

    string res = sol.mergeAlternately(word1, word2);
    cout << res;

    return 0;
}