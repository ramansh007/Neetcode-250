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
// ------------------------------------ My Bruteforce approach giving TLE on Leetcode
// class Solution
// {
// public:
//     vector<vector<string>> groupAnagrams(vector<string> &strs)
//     {
//         vector<vector<string>> res = {};
//         int n = strs.size();
//         int i = 0;
//         // int j = 2;
//         bool resu;
//         vector<bool> visited(n, false);
//         while (i < n)
//         {

//             string s = strs[i];
//             if (visited[i] == false)
//             {
//                 int j = i + 1;
//                 int k = 0;
//                 vector<string> row;
//                 row.push_back(s);
//                 visited[i] = true;
//                 while (j < n)
//                 {
//                     string t = strs[j];
//                     resu = check(s, t);
//                     if (resu)
//                     {
//                         row.push_back(t);
//                         visited[j] = true;
//                     }

//                     j++;
//                 }
//                 res.push_back(row);
//             }

//             i++;
//         }

//         return res;
//     }

//     bool check(string s, string t)
//     {
//         sort(s.begin(), s.end());
//         sort(t.begin(), t.end());
//         if (s == t)
//             return true;
//         else
//             return false;
//     }
// };
// ------------------------------------------ Optimized version using Hash Map
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> res = {};
        vector<string> temp = strs;
        int n = temp.size();
        for (int i = 0; i < n; i++)
        {
            sort(temp[i].begin(), temp[i].end());
        }
        unordered_map<string, vector<string>> map;

        for (int i = 0; i < n; i++)
        {
            map[temp[i]].push_back(strs[i]);
        }

        for (auto it : map)
        {
            res.push_back(it.second);
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
    vector<string> strs = {"act", "pots", "tops", "cat", "stop", "hat"};
    vector<vector<string>> res = sol.groupAnagrams(strs);
    cout << res;

    return 0;
}