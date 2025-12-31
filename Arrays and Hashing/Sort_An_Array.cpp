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
// ---------------------------------------- Selection Sort
// class Solution
// {
// public:
//     vector<int> sortArray(vector<int> &nums)
//     {

//         int n = nums.size();
//         for (int i = 0; i < n - 1; i++)
//         {

//             for (int j = 1; j < n; j++)
//             {
//                 if (nums[j] < nums[j - 1])
//                 {
//                     int temp = nums[j];
//                     nums[j] = nums[j - 1];
//                     nums[j - 1] = temp;
//                 }
//             }
//         }

//         return nums;
//     }
// };

//--------------------------------------------- Merge sort

class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {

        int l = 0;
        int r = nums.size() - 1;
        mergesort(l, r, nums);

        return nums;
    }

    void mergesort(int l, int r, vector<int> &nums)
    {

        if (l >= r)
            return;
        int mid = l + (r - l) / 2;
        mergesort(l, mid, nums);
        mergesort(mid + 1, r, nums);
        merge(l, mid, r, nums);
    }

    void merge(int l, int mid, int r, vector<int> &nums)
    {

        int n1 = mid - l + 1;
        int n2 = r - mid;

        vector<int> L(n1), R(n2);

        for (int i = 0; i < n1; i++)
        {
            L[i] = nums[l + i];
        }
        for (int j = 0; j < n2; j++)
        {
            R[j] = nums[mid + 1 + j];
        }

        int i = 0;
        int j = 0;
        int k = l;

        while (i < n1 && j < n2)
        {
            if (L[i] < R[j])
            {
                nums[k] = L[i];
                i++;
            }
            else
            {
                nums[k] = R[j];
                j++;
            }

            k++;
        }

        while (i < n1)
        {
            nums[k++] = L[i++];
        }
        while (j < n2)
        {
            nums[k++] = R[j++];
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
    vi nums = {5, 10, 3};
    vi res = sol.sortArray(nums);
    cout << res;

    return 0;
}