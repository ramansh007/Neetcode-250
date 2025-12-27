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
// ------------------------------------- solution 1
// class Solution
// {
// public:
//     int majorityElement(vector<int> &nums)
//     {

//         sort(nums.begin(), nums.end());
//         int n = nums[nums.size() / 2];

//         return n;
//     }
// };

// --------------------------------  Solution 2 using hashmap with 2O(N)
// class Solution
// {
// public:
//     int majorityElement(vector<int> &nums)
//     {

//         unordered_map<int, int> map;

//         for (auto it : nums)
//             map[it]++;

//         int max = 0;
//         int maximum;
//         for (auto it : map)
//         {
//             if (it.second > nums.size() / 2)
//             {
//                 maximum = it.first;
//             }
//         }

//         return maximum;
//     }
// };

// ---------------------------------- Better Hash map usage
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {

        unordered_map<int, int> map;
        int res = 0;
        int maxcount = 0;

        for (auto it : nums)
        {
            map[it]++;

            if (map[it] > maxcount)
            {
                res = it;
                maxcount = map[it];
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

    vi nums = {1, 2, 3, 2, 2, 2, 5, 4, 2};

    int res = sol.majorityElement(nums);
    cout << res;

    return 0;
}