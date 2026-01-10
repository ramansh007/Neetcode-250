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
// -------------------------------------- Using Sorting
// class Solution
// {
// public:
// int longestConsecutive(vector<int> &nums)
// {

//     if (nums.size() == 0)
//         return 0;
//     sort(nums.begin(), nums.end());
//     int len = 1;
//     int maxlen = 1;
//     for (int i = 1; i < nums.size(); i++)
//     {
//         if (nums[i] - 1 == nums[i - 1])
//             len++;
//         else if (nums[i] == nums[i - 1])
//             continue;
//         else
//             len = 1;
//         maxlen = max(len, maxlen);
//     }
//     return maxlen;
// }
// };
// ------------------------------------ Using Hashset in O(N) TIme
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        unordered_set<int> set;
        for (int i = 0; i < nums.size(); i++)
        {
            set.insert(nums[i]);
        }
        int maxlen = 1;
        for (auto it : set)
        {
            int curr = 1;
            auto jt = it;
            if (set.find(jt - 1) == set.end())
            {
                while (set.find(jt + 1) != set.end())
                {
                    curr++;
                    jt++;
                }
                maxlen = max(maxlen, curr);
            }
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
    vi nums = {2, 20, 4, 10, 3, 4, 5};
    int res = sol.longestConsecutive(nums);
    cout << res;

    return 0;
}