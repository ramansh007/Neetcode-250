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
// ---------------------------------------- Using While Loop
// class Solution
// {
// public:
//     int search(vector<int> &nums, int target)
//     {

//         int r = nums.size() - 1;
//         int l = 0;

//         while (l <= r)
//         {
//             int mid = l + ((r - l) / 2);
//             if (nums[mid] == target)
//                 return mid;

//             if (nums[mid] > target)
//             {
//                 r = mid - 1;
//             }

//             if (nums[mid] < target)
//             {
//                 l = mid + 1;
//             }
//         }

//         return -1;
//     }
// };
// ---------------------------------------- Recursive function

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {

        int res = bina(0, nums.size() - 1, nums, target);
        return res;
    }

    int bina(int l, int r, vector<int> &nums, int target)
    {
        int mid = l + (r - l) / 2;
        if (l > r)
            return -1;

        if (nums[mid] == target)
            return mid;

        if (nums[mid] < target)
        {
            return bina(mid + 1, r, nums, target);
        }

        if (nums[mid] > target)
        {
            return bina(l, mid - 1, nums, target);
        }
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

    vi nums = {-1, 0, 2, 4, 6, 8};
    int target = 0;

    int res = sol.search(nums, target);
    cout << res;

    return 0;
}