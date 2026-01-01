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
// ------------------------------------------------ My Answer
// class Solution
// {
// public:
//     void sortColors(vector<int> &nums)
//     {
//         int n = nums.size();
//         int count1 = 0;
//         int count2 = 0;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             if (nums[i] == 1)
//                 count1++;
//             if (nums[i] == 2)
//                 count2++;
//         }

//         int k = 0;
//         while (k < (n - (count1 + count2)))
//         {
//             nums[k++] = 0;
//         }

//         while (count1--)
//         {
//             nums[k++] = 1;
//         }

//         while (count2--)
//         {
//             nums[k++] = 2;
//         }
//     }
// };
// ---------------------------------------  Standard optimization ( Dutch National Flag Algorithm )

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {

        int l = 0, r = nums.size() - 1;
        int i = 0;

        while (i <= r)
        {
            if (nums[i] == 0)
            {
                swap(l, i, nums);
                l++;
            }
            else if (nums[i] == 2)
            {
                swap(r, i, nums);
                r--;
                i--;
            }

            i++;
        }
    }

    void swap(int l, int i, vector<int> &nums)
    {
        int temp = nums[l];
        nums[l] = nums[i];
        nums[i] = temp;
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
    vi nums = {2, 0, 2, 1, 1, 0};

    sol.sortColors(nums);
    cout << nums;

    return 0;
}