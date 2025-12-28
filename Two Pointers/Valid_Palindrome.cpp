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
    bool isPalindrome(string s)
    {

        int i = 0;
        string temp;
        while (i < s.size())
        {
            if (isalnum(s[i]) && (!isspace(s[i])))
            {
                temp += tolower(s[i]);
            }
            i++;
        }

        cout << temp << endl;

        int left = 0;
        int right = temp.size() - 1;
        cout << temp[right] << endl;
        while (left < right)
        {
            if (temp[left] != temp[right])
                return false;

            left++;
            right--;
        }

        return true;
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
    string s = "Was it a car or a cat I saw?";
    bool res = sol.isPalindrome(s);
    cout << res;

    return 0;
}