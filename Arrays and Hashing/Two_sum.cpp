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
//     vector<int> twoSum(vector<int> &nums, int target)

//     {

//         int n = nums.size();
//         vi res;
//         for (int i = 0; i < n - 1; i++)
//         {
//             for (int j = i + 1; j < n; j++)
//             {
//                 if ((nums[i] + nums[j]) == target)
//                 {
//                     res.push_back(i);
//                     res.push_back(j);
//                     break;
//                 }
//             }
//         }

//         return res;
//     }
// };

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)

    {
        unordered_map<int, int> map;
        vector<int> res;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int complement = target - nums[i];

            if (map.count(complement))
            {
                return {map[complement], i};
            }

            map[nums[i]] = i;
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

    vector<int> nums = {5, 5};
    int target = 10;

    vi res = sol.twoSum(nums, target);

    cout << "Result -> " << res;

    return 0;
}