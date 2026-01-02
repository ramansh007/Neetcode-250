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
    int numRescueBoats(vector<int> &people, int limit)
    {
        int n = people.size();
        int r = n - 1;
        int l = 0;

        sort(people.begin(), people.end());

        cout << people << endl;
        int count = 0;

        while (l <= r)
        {
            if (people[l] + people[r] > limit)
            {
                r--;
                count++;
            }
            else
            {
                l++;
                r--;
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
    vi people = {1, 3, 2, 3, 2};
    int limit = 3;
    int res = sol.numRescueBoats(people, limit);
    cout << res;

    return 0;
}