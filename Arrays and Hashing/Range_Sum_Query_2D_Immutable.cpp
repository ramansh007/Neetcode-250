class NumMatrix
{
private:
    int rows;
    int cols;
    vector<vector<int>> prefix;

public:
    NumMatrix(vector<vector<int>> &matrix)
    {

        rows = matrix.size();
        if (rows == 0)
            return;

        cols = matrix[0].size();
        prefix = vector<vector<int>>(rows + 1, vector<int>(cols + 1, 0));

        for (int i = 0; i < rows; i++)
        {
            int sum = 0;
            prefix[i][0] = 0;
            for (int j = 0; j < cols; j++)
            {
                sum += matrix[i][j];
                prefix[i][j + 1] = sum;
            }
        }

        // for (int i = 0; i < rows; i++)
        // {
        //     int sum = 0;
        //     ;
        //     for (int j = 0; j <= cols; j++)
        //     {
        //         cout << prefix[i][j] << " ";
        //     }
        //     cout << endl;
        // }
    }

    int
    sumRegion(int row1, int col1, int row2, int col2)
    {

        int x = 0;
        int i = row1;
        while (i <= row2)
        {

            x += (prefix[i][col2 + 1] - prefix[i][col1]);
            i++;
        }

        return x;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */