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
    vector<int> majorityElement(vector<int> &nums)
    {

        int n = nums.size();
        vector<int> res;
        unordered_map<int, int> map;
        for (int i = 0; i < n; i++)
        {
            map[nums[i]]++;
        }

        for (auto it : map)
        {
            if (it.second > n / 3)
                res.push_back(it.first);
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
    vi nums = {5, 2, 3, 2, 2, 2, 2, 5, 5, 5};
    vi res = sol.majorityElement(nums);
    cout << res;

    return 0;
}