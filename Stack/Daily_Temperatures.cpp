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
// ---------------------------------- Bruteforce Approach
// class Solution
// {
// public:
//     vector<int> dailyTemperatures(vector<int> &temperatures)
//     {
//         int n = temperatures.size();
//         vector<int> res;
//         for (int i = 0; i < n; i++)
//         {
//             int temp = temperatures[i];
//             int j = i + 1;
//             int count = 0;
//             while (j < n)
//             {
//                 // cout << "temp " << temp << " temp-2 " << temperatures[j] << endl;
//                 if (temp < temperatures[j])
//                 {
//                     count++;
//                     break;
//                 }
//                 else
//                 {
//                     count++;
//                     j++;
//                 }
//             }
//             if (j < n)
//             {
//                 res.push_back(count);
//             }
//             else
//             {
//                 res.push_back(0);
//             }
//         }

//         return res;
//     }
// };

// ------------------------------------ Optimized Solution in O(N) with Stacks
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {

        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<pair<int, int>> stack;
        for (int i = 0; i < temperatures.size(); i++)
        {

            int t = temperatures[i];
            while (!stack.empty() && t > stack.top().first)
            {
                auto pair = stack.top();
                stack.pop();
                res[pair.second] = i - pair.second;
            }

            stack.push({t, i});
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
    vi temperatures = {30, 38, 30, 36, 35, 40, 28};
    vi res = sol.dailyTemperatures(temperatures);
    cout << res;

    return 0;
}