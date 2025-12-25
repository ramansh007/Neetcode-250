#include <bits/stdc++.h>
using namespace std;

// =========================
// 1. TYPEDEFS (Speed up typing)
// =========================
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;

// =========================
// 2. DEBUGGING MAGIC (Print vectors & pairs automatically)
// =========================
// Allow printing pairs: cout << pair
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p)
{
    return os << "(" << p.first << ", " << p.second << ")";
}

// Allow printing vectors: cout << vector
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
// 3. SOLUTION CLASS (Copy from LeetCode)
// =========================
class Solution
{
public:
    vector<int> getConcatenation(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> result(2 * n);

        for (int i = 0; i < 2 * n; i++)
        {
            result[i] = nums[i % n];
        }
        return result;
    }
};

// =========================
// 4. MAIN FUNCTION (Local Testing)
// =========================
int main()
{
    // FAST I/O (Essential for Competitive Programming)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    // --- TEST CASE ---
    vi nums = {1, 4, 1, 2};

    // Call function
    vi result = sol.getConcatenation(nums);

    // Print result using our "Magic" printer
    cout << "Result: " << result << endl;

    return 0;
}