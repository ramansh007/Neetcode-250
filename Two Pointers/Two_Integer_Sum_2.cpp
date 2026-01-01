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
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int l = 0;
        int r = numbers.size() - 1;
        vector<int> res;

        while (l < r)
        {
            int sum = numbers[l] + numbers[r];
            if (sum == target)
            {
                res.push_back(l + 1);
                res.push_back(r + 1);
                break;
            }
            else
            {
                if (sum > target)
                {
                    r--;
                }
                if (sum < target)
                {
                    l++;
                }
            }

            sum = 0;
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
    vi numbers = {1, 2, 3, 4};
    int target = 3;

    vector<int> res = sol.twoSum(numbers, target);
    cout << res;

    return 0;
}