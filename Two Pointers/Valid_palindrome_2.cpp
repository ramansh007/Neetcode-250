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
// ---------------------------------- Using string reversal
class Solution
{
public:
    bool validPalindrome(string s)
    {
        int left = 0;
        int right = s.size() - 1;
        int valid = 0;
        while (left < right)
        {
            if (s[left] != s[right])
            {
                valid = 0;
                break;
            }

            left++;
            right--;
            valid = 1;
        }

        if (valid)
            return true;

        if (!valid)
        {
            int left1 = left;
            int right1 = right - 1;
            int left2 = left + 1;
            int right2 = right;

            string substring_1 = s.substr(left1, right1 - left1 + 1);
            string substring_2 = s.substr(left2, right2 - left2 + 1);

            string t1 = substring_1;
            reverse(t1.begin(), t1.end());

            string t2 = substring_2;
            reverse(t2.begin(), t2.end());

            if (substring_1 == t1 || substring_2 == t2)
                valid = 1;

            return valid;
        }
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
    string s = "abc";
    bool res = sol.validPalindrome(s);
    cout << res;

    return 0;
}
