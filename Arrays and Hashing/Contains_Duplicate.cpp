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
    bool hasDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> map;
        bool res = 0;
        ;

        for (int i = 0; i < n; i++)
        {
            map[nums[i]]++;
        }

        // it is an iterator pointing to a pair
        for (auto it = map.begin(); it != map.end(); it++)
        {
            if ((it->second) > 1)
            {
                res = 1;
                break;
            }
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
    // --- TEST CASE ---
    vi nums = {2, 2, 1, 1, 3, 1, 2, 3, 1, 4};

    // Call function
    bool result = sol.hasDuplicate(nums);

    // Print result using our "Magic" printer
    cout << "Result: " << result << endl;

    return 0;
}