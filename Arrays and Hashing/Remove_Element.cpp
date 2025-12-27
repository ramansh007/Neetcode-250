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
// ------------------------------- Erase index from Vector Method
// class Solution
// {
// public:
//     int removeElement(vector<int> &nums, int val)
//     {

//         int n = nums.size();
//         int count = 0;

//         for (int i = 0; i < nums.size(); i++)
//         {

//             if (nums[i] == val)
//             {
//                 nums.erase(nums.begin() + i);
//                 i--;
//                 count++;
//             }
//         }

//         cout << nums << endl;

//         return n - count;
//     }
// };

// ---------------------------------- Using unordered_map --------------------------------
// class Solution
// {
// public:
//     int removeElement(vector<int> &nums, int val)
//     {

//         unordered_map<int, int> map;
//         int n = nums.size();
//         int count = 0;
//         for (int i = 0; i < n; i++)
//         {
//             if (nums[i] != val)
//             {
//                 map[nums[i]]++;
//                 count++;
//             }
//         }

//         int j = 0;
//         for (auto it : map)
//         {
//             while ((it.second)--)
//             {
//                 nums[j] = it.first;
//                 j++;
//             }
//         }

//         return count;
//     }
// };
// --------------------------------------- Using two pointers
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {

        int k = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != val)
                nums[k++] = nums[i];
        }

        return k;
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

    vi nums = {1, 1, 2, 3, 4};
    int val = 1;

    int res = sol.removeElement(nums, val);
    cout << res;

    return 0;
}