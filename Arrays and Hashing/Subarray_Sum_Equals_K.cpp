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
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        prefix[0] = 0;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            prefix[i + 1] = sum;
        }
        // for(int i=0;i<n+1;i++){
        //     cout<<prefix[i]<<" ";
        // }
        int count = 0;
        for (int i = n; i > 0; i--)
        {
            int x = prefix[i];
            for (int j = i - 1; j >= 0; j--)
            {
                if (x - prefix[j] == k)
                    count++;
            }
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
    vi nums = {2, -1, 1, 2};
    int k = 2;
    int res = sol.subarraySum(nums, k);
    cout << res;

    return 0;
}