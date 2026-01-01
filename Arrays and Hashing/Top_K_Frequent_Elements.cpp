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
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> map;
        vector<int> res = {};
        for (int i = 0; i < nums.size(); i++)
        {
            map[nums[i]]++;
        }

        while (k--)
        {
            max(map, res);
        }

        return res;
    }

    void max(unordered_map<int, int> &map, vector<int> &res)
    {
        int max = -1;
        int key;
        for (auto it : map)
        {
            if (it.second > max)
            {
                max = it.second;
                key = it.first;
            }
        }
        res.push_back(key);
        map.erase(key);
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
    vi nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    vi res = sol.topKFrequent(nums, k);
    cout << res;

    return 0;
}