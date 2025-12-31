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
// ----------------------------------------------- My solution using Map
// class Solution
// {
// public:
//     string longestCommonPrefix(vector<string> &strs)
//     {
//         int min = strs[0].size();
//         // Chossing the minimum length among the strings
//         for (int i = 1; i < strs.size(); i++)
//         {
//             if (strs[i].size() < min)
//                 min = strs[i].size();
//         }

//         string res = "";
//         int i = 0;
//         int count = 0;
//         while (i < min)
//         {
//             int j = 0;
//             unordered_map<char, int> map; //  Map to check if the characters added are all same and count = vector size
//             while (j < strs.size())
//             {
//                 map[(strs[j][i])]++;
//                 j++;
//             }

//             if (map.size() != 1) // If single Key that means all char among strings is same
//                 break;
//             else
//                 res += strs[0][i];

//             i++;
//         }

//         return res;
//     }
// };
// ----------------------------------------- Without Map
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int min = strs[0].size();
        // Chossing the minimum length among the strings
        for (int i = 1; i < strs.size(); i++)
        {
            if (strs[i].size() < min)
                min = strs[i].size();
        }

        string res = "";
        int i = 0;
        while (i < min)
        {
            int j = 1;
            int flag = 0;
            char s = strs[0][i];
            while (j < strs.size())
            {
                if (strs[j][i] != s) // Comparing the different string characters to be same as initial one
                {
                    flag = 1;
                    break;
                }
                j++;
            }

            if (!flag)
            {
                res += strs[0][i];
                i++;
            }
            else
                break;
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
    vector<string> strs = {"bat", "bag", "bank", "band"};
    string res = sol.longestCommonPrefix(strs);
    cout << res;

    return 0;
}