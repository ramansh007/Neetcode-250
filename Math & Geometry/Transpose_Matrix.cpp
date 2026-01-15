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
    vector<vector<int>> transpose(vector<vector<int>> &matrix)
    {

        // vector<vector<int>> trans;

        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> trans(m, vector<int>(n));

        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < m; j++)
            {

                trans[j][i] = matrix[i][j];
            }
        }

        return trans;
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
    vvi matrix = {
        {2, 1},
        {-1, 3}};

    vvi res = sol.transpose(matrix);
    cout << res;

    return 0;
}