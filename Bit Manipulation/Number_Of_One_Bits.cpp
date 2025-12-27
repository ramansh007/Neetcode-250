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
// --------------------------------- Solution using XOR operation
// class Solution
// {
// public:
//     int hammingWeight(uint32_t n)
//     {
//         int count = 0;
//         for (int i = 0; i < 32; i++)
//         {
//             if (n & 1 == 1)
//                 count++;
//             n = n >> 1;
//         }
//         return count;
//     }
// };

// ---------------------------------- Brian Kernighan’s Algorithm
class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int count = 0;
        while (n)
        {
            n = (n & (n - 1));
            count++;
        }

        return count;
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
    uint32_t n = 00000000000000000000000000010111;
    int res = sol.hammingWeight(n);
    cout << res;

    return 0;
}