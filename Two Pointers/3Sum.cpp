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
    vector<vector<int>> threeSum(vector<int> &nums)
    {

        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int mid = 0;
        while (mid < n)
        {
            if (mid > 0 && nums[mid] == nums[mid - 1]) // To remove duplicacy of mid
            {
                mid++;
                continue;
            }

            int i = mid + 1;
            int j = n - 1;
            int target = -nums[mid];
            while (i < j)
            {

                int sum = nums[i] + nums[j];
                if (sum == target)
                {
                    res.push_back({nums[i], nums[mid], nums[j]});
                    while (i < j && nums[i] == nums[i + 1]) // To remove duplicacy of Other elements
                        i++;
                    // while(i<j && nums[j] == nums[j-1]) j--;

                    i++;
                    j--;
                }

                else if (sum < target)
                    i++;
                else if (sum > target)
                    j--;
            }
            mid++;
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
    vi nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res;
    res = sol.threeSum(nums);

    cout << res;

    return 0;
}