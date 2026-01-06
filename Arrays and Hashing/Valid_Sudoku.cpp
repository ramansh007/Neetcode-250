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
    bool isValidSudoku(vector<vector<char>> &board)
    {
        int n = 9;
        // Checking Verticles
        for (int i = 0; i < n; i++)
        {
            unordered_set<char> set;
            for (int j = 0; j < n; j++)
            {
                if (set.count(board[i][j]))
                {
                    return false;
                }
                if (board[i][j] >= '1' && board[i][j] <= '9')
                    set.insert(board[i][j]);
            }
        }
        // Checking Horizontals
        for (int i = 0; i < n; i++)
        {
            unordered_set<char> set2;
            for (int j = 0; j < n; j++)
            {
                if (set2.count(board[j][i]))
                {
                    return false;
                }
                if (board[j][i] >= '1' && board[j][i] <= '9')
                    set2.insert(board[j][i]);
            }
        }
        // Checking 3x3 Squares
        int l = 0;
        int r = 0;
        while (r < 9 && l < 9)
        {
            unordered_set<char> set;
            for (int i = l; i < l + 3; i++)
            {
                for (int j = r; j < 3 + r; j++)
                {
                    if (set.count(board[i][j]))
                    {
                        return false;
                    }
                    if (board[i][j] >= '1' && board[i][j] <= '9')
                        set.insert(board[i][j]);
                }
            }
            r += 3;
        }
        l = 3;
        r = 0;
        while (r < 9 && l < 9)
        {
            unordered_set<char> set;
            for (int i = l; i < l + 3; i++)
            {
                for (int j = r; j < 3 + r; j++)
                {
                    if (set.count(board[i][j]))
                    {
                        return false;
                    }
                    if (board[i][j] >= '1' && board[i][j] <= '9')
                        set.insert(board[i][j]);
                }
            }
            r += 3;
        }
        l = 6;
        r = 0;
        while (r < 9 && l < 9)
        {
            unordered_set<char> set;
            for (int i = l; i < l + 3; i++)
            {
                for (int j = r; j < 3 + r; j++)
                {
                    if (set.count(board[i][j]))
                    {
                        return false;
                    }
                    if (board[i][j] >= '1' && board[i][j] <= '9')
                        set.insert(board[i][j]);
                }
            }
            r += 3;
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
    vector<vector<char>> board =
        {
            {'1', '2', '.', '.', '3', '.', '.', '.', '.'},
            {'4', '.', '.', '5', '.', '.', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '.', '3'},
            {'5', '.', '.', '.', '6', '.', '.', '.', '4'},
            {'.', '.', '.', '8', '.', '3', '.', '.', '5'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '.', '.', '.', '.', '.', '2', '.', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '8'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    bool res = sol.isValidSudoku(board);
    cout << res;

    return 0;
}