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
// ------------------------------------------ Bruteforce Approach
// class Solution
// {
// public:
//     vector<int> productExceptSelf(vector<int> &nums)
//     {
//         vector<int> res = {};
//         int n = nums.size();
//         for (int i = 0; i < n; i++)
//         {
//             int product = 1;

//             for (int j = 0; j < n; j++)
//             {
//                 if (i != j)
//                 {
//                     product *= nums[j];
//                 }
//             }
//             res.push_back(product);
//         }
//         return res;
//     }
// };

// ---------------------------------------------- Optimized Solution ( Prefix/Suffix )
// class Solution
// {
// public:
//     vector<int> productExceptSelf(vector<int> &nums)
//     {
//         int n = nums.size();
//         vector<int> prefix(n), postfix(n);
//         vector<int> res;

//         // ----- Calculation of Prefix and Postfix
//         for (int i = 0; i < n; i++)
//         {
//             prefix[i] = nums[i] * pre;
//             pre = prefix[i];
//         }

//         for (int i = n - 1; i >= 0; i--)
//         {
//             postfix[i] = post * nums[i];
//             post = postfix[i];
//         }
//         //------------ Final traversal
//         for (int i = 0; i < n; i++)
//         {
//             if (i == 0)
//             {
//                 res.push_back(postfix[i + 1]);
//             }
//             else if (i < n - 1)
//             {
//                 res.push_back((prefix[i - 1]) * (postfix[i + 1]));
//             }
//             else
//             {
//                 res.push_back(prefix[i - 1]);
//             }
//         }

//         return res;
//     }
// };

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res(n, 1);

        // ----- Calculation of output

        for (int i = 1; i < n; i++)
        {
            res[i] = res[i - 1] * nums[i - 1];
        }

        int postfix = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            res[i] *= postfix;
            postfix *= nums[i];
        }

        cout << res;

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
    vi nums = {1, 2, 3};
    vi res = sol.productExceptSelf(nums);
    cout << res;

    return 0;
}