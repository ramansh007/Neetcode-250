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
// ------------------------------------- Two pointers with Extra space O(m+ n)
// class Solution
// {
// public:
//     void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
//     {

//         vector<int> arr = nums1;
//         int j = 0, i = 0;
//         int k = 0;

//         while (i < m && j < n)
//         {
//             if (nums1[i] < nums2[j])
//             {
//                 arr[k++] = nums1[i++];
//             }
//             else
//             {
//                 arr[k++] = nums2[j++];
//             }
//         }

//         while (i < m)
//             arr[k++] = nums1[i++];
//         while (j < n)
//             arr[k++] = nums2[j++];

//         nums1 = arr;
//     }
// };
// --------------------------------------------- Without Extra Space using Two Pointers
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int last = m + n - 1;
        int i = m - 1, j = n - 1;
        while (i >= 0 and j >= 0)
        {
            if (nums2[j] > nums1[i])
            {
                nums1[last] = nums2[j];
                j--;
                last--;
            }
            else
            {
                nums1[last] = nums1[i];
                i--;
                last--;
            }
        }

        while (j >= 0)
        {
            nums1[last--] = nums2[j];
            j--;
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
    vi nums1 = {10, 20, 20, 40, 0, 0};
    int m = 4;
    vi nums2 = {1, 2};
    int n = 2;

    sol.merge(nums1, m, nums2, n);
    cout << nums1;

    return 0;
}